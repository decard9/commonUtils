/*
 * utilCls2.h
 *
 *  Created on: Nov 24, 2014
 *      Author: decard9
 */

#ifndef UTILCLS2_H_
#define UTILCLS2_H_
#include <string>

namespace mynamespace {

class utilCls2 {
public:
	utilCls2();
	virtual ~utilCls2();


	void copyFile1(char * targetFile, char * destFile);
	int getUserUid(char * name);


	std::string replaceStr(std::string srcString, std::string findString, std::string replaceString);
//	static std::string split(std::string org, std::string headStr,int replacePos, std::string FromStr, std::string ToStr , std::string delemeter = ":" );
	std::string split(std::string org, std::string headStr,int replacePos, std::string FromStr, std::string ToStr  );
	std::string GetSystemOutput(char* cmd);
	void executeSystemCommand(char * addr, char* cmd);
};

} /* namespace mynamespace */

#endif /* UTILCLS2_H_ */
