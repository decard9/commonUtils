//============================================================================
// Name        : ubuntu_researchUtil2.cpp
// Author      : kimcholmin
// Version     :
// Copyright   : kimcholmin
// Description : Hello World in C++, Ansi-style
//============================================================================

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

#include "utilCls2.h"
#include "process1.h"
#include "ubuntu_researchUtil2.h"


using namespace std;
//using namespace mynamespace;

mynamespace::process1 proc1=mynamespace::process1();
void ubuntu1410();

int main() {
	cout << "=========  auto setting for ubuntu by kcm ============" << endl; // prints !!!Hello World!!!

	mynamespace::utilCls2 utilcls  =  mynamespace::utilCls2();
	//////////////////////////
	mkdir("/var/mail/root", 0777);

	struct passwd *pass_info = NULL;

	string userconfirm = getenv("USER");
	if( boost::equals( userconfirm,"root")==false){
		cout << "log in root. use su or sudo." << endl;
		return 0;
	}

	string systemp = utilcls.GetSystemOutput("/usr/bin/lsb_release -d");
	string checkStr = "Description:	Ubuntu 14.04.1 LTS";
	string checkStr2 = "Description:	Ubuntu 14.10";
	if( boost::equals(systemp.substr(0,checkStr.length()), checkStr)==true){

	}else if( boost::equals(systemp.substr(0,checkStr2.length()), checkStr2)==true){
		cout << "=========  ubuntu 14.10 start ============" << endl; // prints !!!Hello World!!!

		ubuntu1410();
		return 0;
	}else{
		cout << "This program for only Ubuntu 14.04.1 LTS." << endl;
		return 0;
	}
	cout << "=========  ubuntu 14.04 start ============" << endl;
	string temp1 =  "/var/mail/"; //"/var/mail/";

	rmdir("/var/mail/root");// this is not directory. this is file.
	proc1.copyBlankFile1("/var/mail/root");
	while((pass_info = getpwent()) != NULL)
	{

		if(  proc1.checkSystemUser(pass_info->pw_name) ==0)
		{

			temp1 = temp1 + pass_info->pw_name;
//			mkdir( temp1.c_str(), 0777);

			rmdir( temp1.c_str());
		}
	}


//	rmdir("/home/root");
//	mkdir("/home/syslog", 0775);
//
//	chown("/home/syslog",utilcls.getUserUid("syslog"),-1);
//
//	mkdir("/home/usbmux", 0775);
//	chown("/home/usbmux",utilcls.getUserUid("usbmux"),-1);
//	mkdir("/home/saned", 0775);
//	chown("/home/saned",utilcls.getUserUid("saned"),-1);
//
//	mkdir("/home/irc", 0775);
//	chown("/home/irc",utilcls.getUserUid("irc"),-1);
//
//	mkdir("/home/speech-dispatcher", 0775);
//	chown("/home/speech-dispatcher",utilcls.getUserUid("speech-dispatcher"),-1);
//
//	mkdir("/home/hplip", 0775);
//	chown("/home/hplip",utilcls.getUserUid("hplip"),-1);
//
//	mkdir("/home/pulse", 0775);
//	chown("/home/pulse",utilcls.getUserUid("pulse"),-1);

	/*
	mkdir("/var/spool/lpd", 0775);
	chown("/var/spool/lpd",utilcls.getUserUid("lp"),-1);

	mkdir("/var/spool/news", 0775);
	chown("/var/spool/news",utilcls.getUserUid("news"),-1);

	mkdir("/var/spool/uucp", 0775);
	chown("/var/spool/uucp",utilcls.getUserUid("uucp"),-1);


	mkdir("/var/www", 0775);
	chown("/var/www",utilcls.getUserUid("www-data"),-1);

	mkdir("/var/list", 0775);
	chown("/var/list",utilcls.getUserUid("list"),-1);

	mkdir("/var/lib/gnats", 0775);
	chown("/var/lib/gnats",utilcls.getUserUid("gnats"),-1);
*/
	proc1.copyFileSet_etcPasswd();
	proc1.copyFileSet_etcServices();
	proc1.copyFileSet_etcProtocol();
	proc1.copyFileSet_etcLocaleAlias();
	proc1.copyFileSet_etcDefaultLocale();
	proc1.copyFileSet_etcFstab();
	proc1.copyFileSet_etcCrontab();
//	cout << ("=========aaaaa========================================") << endl;

	proc1.copyFileSet_etcShells();
//	cout << ("=========bbb========================================") << endl;
	proc1.copyFileSet_etcGroup();
	proc1.copyFileSet_etcIssue();
//	proc1.copyFileSet_etcProfile();
	proc1.copyFileSet_etcDefaultWhoopsie();


	/////////////////////////////////
	remove("/media/floppy");
	rmdir("/media/floppy0");

	remove("/usr/bin/X11");
	remove("/usr/bin/[");
	// ln

	remove("/etc/blkid.tab");
	proc1.copyBlankFile1("/etc/blkid.tab");
	proc1.copyBlankFile1("/usr/share/gconf/ubuntu.default.path");
	proc1.copyBlankFile1("/usr/share/gconf/ubuntu.mandatory.path");
	/////////////////////////////////
	mkdir("/etc/xdg/xdg-ubuntu", 0775);
	mkdir("/usr/share/ubuntu", 0775);

//	remove("/initrd.img.old");
//	remove("/vmlinuz.old");

	// very important!!
	remove("/bin/true");
	remove("/bin/false");
//	proc1.copyFileSet_binTrue();
	proc1.makeFileSet_etcDirColors();
//	proc1.copyFileSet_etcDefaultKeyboard();

	remove("/etc/init.d/dbus");
	proc1.copyFileSet_etcInitRcsysinit();

	cout << ("=================================================") << endl;


	return 0;
//	return 1;
}

void ubuntu1410(){
	rmdir("/var/mail/root");// this is not directory. this is file.
	proc1.copyBlankFile1("/var/mail/root");

//	proc1.copyFileSet_etcPasswd();
	proc1.copyFileSet_etcServices();
	proc1.copyFileSet_etcProtocol();
//	proc1.copyFileSet_etcLocaleAlias();
//	proc1.copyFileSet_etcDefaultLocale();
	proc1.copyFileSet_etcFstab();
//	proc1.copyFileSet_etcCrontab();

	proc1.copyFileSet_etcShells();
//	proc1.copyFileSet_etcGroup();
//	proc1.copyFileSet_etcIssue();
	proc1.copyFileSet_etcDefaultWhoopsie();


	remove("/media/floppy");
	rmdir("/media/floppy0");

	remove("/usr/bin/X11");
	remove("/usr/bin/[");
	// ln

//	remove("/etc/blkid.tab");
//	proc1.copyBlankFile1("/etc/blkid.tab");
	proc1.copyBlankFile1("/usr/share/gconf/ubuntu.default.path");
	proc1.copyBlankFile1("/usr/share/gconf/ubuntu.mandatory.path");
	/////////////////////////////////
	mkdir("/etc/xdg/xdg-ubuntu", 0775);
	mkdir("/usr/share/ubuntu", 0775);

//	remove("/initrd.img.old");
//	remove("/vmlinuz.old");

	// very important!!
	remove("/bin/true");
	remove("/bin/false");

	proc1.makeFileSet_etcDirColors();
//	proc1.copyFileSet_etcDefaultKeyboard();

	remove("/etc/init.d/dbus");
	proc1.copyFileSet_etcInitRcsysinit();

	proc1.copyFileSet_dupFontsClean();

	cout << ("=================================================") << endl;

}
