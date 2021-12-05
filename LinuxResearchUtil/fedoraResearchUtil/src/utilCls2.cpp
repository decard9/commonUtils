/*
 * utilCls2.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: decard9
 */

#include "utilCls2.h"


#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <wait.h>

using namespace std;

namespace mynamespace {

utilCls2::utilCls2() {
	// TODO Auto-generated constructor stub

}

utilCls2::~utilCls2() {
	// TODO Auto-generated destructor stub
}


void utilCls2::copyFile1(char * targetFile, char * destFile){
	/////////////////////////ready tmp file
/*
	int read_fd;
	int write_fd;
	struct stat stat_buf;
	off_t offset = 0;


	read_fd = open (targetFile, O_RDONLY);

	fstat (read_fd, &stat_buf);

	write_fd = open (destFile, O_WRONLY | O_CREAT, stat_buf.st_mode);

	sendfile (write_fd, read_fd, &offset, stat_buf.st_size);
	close (read_fd);
	close (write_fd);
*/

    char buf[BUFSIZ];
    size_t size;

    FILE* source = fopen(targetFile, "rb");
    FILE* dest = fopen(destFile, "wb");

    // clean and more secure
    // feof(FILE* stream) returns non-zero if the end of file indicator for stream is set

    while (size = fread(buf, 1, BUFSIZ, source)) {
        fwrite(buf, 1, size, dest);
    }

    fclose(source);
    fclose(dest);





}


void utilCls2::copyFile2(const char * targetFile,const char * destFile){
	/////////////////////////ready tmp file

    char buf[BUFSIZ];
    size_t size;

    FILE* source = fopen(targetFile, "rb");
    FILE* dest = fopen(destFile, "wb");

    // clean and more secure
    // feof(FILE* stream) returns non-zero if the end of file indicator for stream is set

    while (size = fread(buf, 1, BUFSIZ, source)) {
        fwrite(buf, 1, size, dest);
    }

    fclose(source);
    fclose(dest);

}

int utilCls2::getUserUid(char * name){
	struct passwd *pass_info2 = NULL;

//	cout << name << endl;
	setpwent();
	while((pass_info2 = getpwent()) != NULL)
	{
//		cout << pass_info2->pw_name << endl;

		if (strncmp(name, pass_info2->pw_name, strlen(name)) == 0)
		{
			return pass_info2->pw_uid;
		}
	}
	return 0;
}

std::string utilCls2::replaceStr(std::string srcString, std::string findString, std::string replaceString){

	int offset=0;
	offset = srcString.find( findString, offset);
	if( std::string::npos == offset ){}
	else{
		srcString.replace( offset, findString.length(), replaceString );
	}
	return srcString;
}


std::string utilCls2::split(std::string orgStr, std::string headStr, int replacePos,
		std::string FromStr, std::string ToStr  ){
	std::string delimeter = ":";
	std::vector<std::string> strs;
	boost::split(strs, orgStr, boost::is_any_of(delimeter));

	if( boost::equals(strs[0], headStr)==true){
		return orgStr;
	}
//	if( strs[0].compare(headStr)!=0){
//		return orgStr;
//	}
	if( boost::equals(strs[replacePos], FromStr)==true){
		strs[replacePos] = ToStr;
	}

//	if( strs[replacePos].compare(FromStr)==0){
//		strs[replacePos] = ToStr;
//	}


	std::string joined = boost::join(strs,delimeter);
	//std::cout << joined << std::endl;
	return joined;
}

std::string utilCls2::GetSystemOutput(char* cmd){
    int buff_size = 100;
    char* buff = new char[buff_size];

//	char* ret = NULL;
	string str = "";

    int fd[2];
    int old_fd[3];
    pipe(fd);


	old_fd[0] = dup(STDIN_FILENO);
	old_fd[1] = dup(STDOUT_FILENO);
	old_fd[2] = dup(STDERR_FILENO);

	int pid = fork();
	switch(pid){
		case 0:
				close(fd[0]);
				close(STDOUT_FILENO);
				close(STDERR_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				dup2(fd[1], STDERR_FILENO);
				system(cmd);
				//execlp((const char*)cmd, cmd,0);
				close (fd[1]);
				exit(0);
				break;
		case -1:
				cerr << "GetSystemOutput/fork() error\n" << endl;
				exit(1);
		default:
				close(fd[1]);
				dup2(fd[0], STDIN_FILENO);

				int rc = 1;
				while (rc > 0){
						rc = read(fd[0], buff, buff_size);
						str.append(buff, rc);
						//memset(buff, 0, buff_size);
				}

//                        ret = new char [strlen((char*)str.c_str())];

//                        strcpy(ret, (char*)str.c_str());

				waitpid(pid, NULL, 0);
				close(fd[0]);
	}

	dup2(STDIN_FILENO, old_fd[0]);
	dup2(STDOUT_FILENO, old_fd[1]);
	dup2(STDERR_FILENO, old_fd[2]);

	free(buff);

//    return ret;
	return str;
}


void utilCls2::executeSystemCommand(char * addr, char* cmd){
	pid_t pid;
	int status;

	pid = fork();
	if(pid ==0){
		execlp(addr, cmd, (char*)0);
	}else if( pid>0){
		waitpid(pid, &status,0);

	}else{
		printf("fail to fork");
	}
}

} /* namespace mynamespace */
