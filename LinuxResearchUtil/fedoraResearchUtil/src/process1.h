/*
 * process1.h
 *
 *  Created on: Nov 25, 2014
 *      Author: decard9
 */

#ifndef PROCESS1_H_
#define PROCESS1_H_
#include "utilCls2.h"

namespace mynamespace {

class process1 {
private:
	utilCls2 utilcls ;
public:
	process1();
	virtual ~process1();

	void copyBlankFile1( char * destFile);
	int checkSystemUser( char * param);
	int copyFileSet_etcPasswd();
	int copyFileSet_etcServices();
	int copyFileSet_etcProtocol();
	int copyFileSet_etcLocaleAlias();
	int copyFileSet_etcDefaultLocale();
	int copyFileSet_etcFstab();
	int copyFileSet_etcCrontab();
	int copyFileSet_etcShells();
	int copyFileSet_etcGroup();
	int copyFileSet_etcIssue();
	int copyFileSet_etcProfile();
	int copyFileSet_binTrue();
	int copyFileSet_etcDefaultWhoopsie();
	int makeFileSet_etcDirColors();
	int copyFileSet_etcDefaultKeyboard();
	int copyFileSet_etcInitRcsysinit();
	int copyFileSet_dupFontsClean();
	int copyFileSet_etcConfFiles();
};

} /* namespace mynamespace */

#endif /* PROCESS1_H_ */
