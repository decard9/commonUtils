//============================================================================
// Name        : fedoraResearchUtil.cpp
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

using namespace std;

int main() {

	mynamespace::process1 proc1=mynamespace::process1();

	cout << "=========  auto setting for fedora 20 by kcm ============" << endl; // prints !!!Hello World!!!

	mynamespace::utilCls2 utilcls  =  mynamespace::utilCls2();
	//////////////////////////
//	proc1.copyFileSet_etcFstab();

	string userconfirm = getenv("USER");
	if( boost::equals( userconfirm,"root")==false){
		cout << "log in root. use su or sudo." << endl;
		return 0;
	}

	string systemp = utilcls.GetSystemOutput("/usr/bin/lsb_release -d");
	string checkStr = "Description:	Fedora release 20 (Heisenbug)";
	if( boost::equals(systemp.substr(0,checkStr.length()), checkStr)==true){

	}
	else{
		cout << "This program for only Fedora 20." << endl;
		return 0;
	}
	cout << "=========  fedora 20 start ============" << endl;
//		lsb_release -d
//	Description:	Fedora release 20 (Heisenbug)
//
//		cat /etc/issue
//	Fedora release 20 (Heisenbug)
//	Kernel \r on an \m (\l)


	remove("/usr/bin/[");
	// ln

	// very important!!
	remove("/bin/true");
	remove("/bin/false");
	proc1.makeFileSet_etcDirColors();
	proc1.copyFileSet_etcFstab();
	mkdir( "/usr/lib64/qt-3.3/include", 0777);

	proc1.copyFileSet_dupFontsClean();

	cout << ("=================================================") << endl;


	return 0;
}
