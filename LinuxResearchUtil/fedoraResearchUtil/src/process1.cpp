/*
 * process1.cpp
 *
 *  Created on: Nov 25, 2014
 *      Author: decard9
 */


#include "process1.h"

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

//#include "utilCls2.h"


using namespace std;

namespace mynamespace {

process1::process1() {
	// TODO Auto-generated constructor stub
	utilcls = mynamespace::utilCls2();
}

process1::~process1() {
	// TODO Auto-generated destructor stub
}



void process1::copyBlankFile1( char * destFile){
	/////////////////////////ready tmp file
	utilcls.copyFile1("resource2/blank.txt",  destFile);

}


int process1::checkSystemUser( char * param){
//	std::string strn[2]  = {"a","b"};

	char * strn2[34] = {"root", "daemon","bin","sys" ,"sync","games","man","lp"
	,"mail","uucp","proxy","www-data","backup","list","irc","gnats","nobody"
	,"libuuid","syslog","messagebus","usbmux","dnsmasq","avahi-autoipd","kernoops"
	,"rtkit","saned","whoopsie","speech-dispatcher","avahi","lightdm","colord"
	,"hplip","pulse","news"};

	int rtn = 0;

	for(int i=0; i< 34 ; i++){
		if (strncmp( strn2[i], param, strlen(param)) == 0){
			rtn = 1;
		}

		if( strncmp( "guest", param, 5) == 0){
			rtn =1;
		}
	}
	return rtn;
}



int process1::copyFileSet_etcPasswd(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "/tmp/ubuntu_researchUtil_passwd_tempfile.txt";

	if ( fp   = fopen( "/etc/passwd", "r"))
	{
		fp2 = fopen(tempFileName,"w");

		while( 0< fgets(buf, sizeof(buf), fp)){
			temp1 = buf;
			/*
			temp1 = replaceStr(temp1,":/var/run/ircd:",":/home/irc:");
			temp1 = replaceStr(temp1,":/var/run/speech-dispatcher:",":/home/speech-dispatcher:");
			temp1 = replaceStr(temp1,":/var/run/hplip:",":/home/hplip:");
			temp1 = replaceStr(temp1,":/var/run/pulse:",":/home/pulse:");

			temp1 = replaceStr(temp1,"hplip:x:114:7:","hplip:x:114:61:");
			temp1 = replaceStr(temp1,"speech-dispatcher:x:110:29:","speech-dispatcher:x:110:62:");
			temp1 = replaceStr(temp1,"usbmux:x:103:46:","usbmux:x:103:63:");

			temp1 = replaceStr(temp1,"dnsmasq:x:104:65534:","dnsmasq:x:104:64:");
			temp1 = replaceStr(temp1,"kernoops:x:106:65534:","kernoops:x:106:65:");
			temp1 = replaceStr(temp1,"nobody:x:65534:65534:","nobody:x:65534:66:");
			temp1 = replaceStr(temp1,"sync:x:4:65534:","sync:x:4:67:");
*/
/* restore
			temp1 = utilcls.split( temp1, "irc",5, "/var/run/ircd","/home/irc");
			temp1 = utilcls.split( temp1, "speech-dispatcher", 5, "/var/run/speech-dispatcher","/home/speech-dispatcher");
			temp1 = utilcls.split( temp1, "hplip", 5, "/var/run/hplip","/home/hplip");
			temp1 = utilcls.split( temp1, "pulse", 5, "/var/run/pulse","/home/pulse");

			temp1 = utilcls.split( temp1, "hplip",3, "7","61");
			temp1 = utilcls.split( temp1, "speech-dispatcher", 3, "29","62");
			temp1 = utilcls.split( temp1, "usbmux", 3, "46","63");

			temp1 = utilcls.split( temp1, "dnsmasq", 3, "65534","64");
			temp1 = utilcls.split( temp1, "kernoops", 3, "65534","65");
			temp1 = utilcls.split( temp1, "nobody", 3, "65534","66");
			temp1 = utilcls.split( temp1, "sync", 3, "65534","67");
*/
			temp1 = utilcls.split( temp1, "irc",5,"/home/irc", "/var/run/ircd");
			temp1 = utilcls.split( temp1, "speech-dispatcher", 5,"/home/speech-dispatcher", "/var/run/speech-dispatcher");
			temp1 = utilcls.split( temp1, "hplip", 5,"/home/hplip", "/var/run/hplip");
			temp1 = utilcls.split( temp1, "pulse", 5,"/home/pulse", "/var/run/pulse");

			temp1 = utilcls.split( temp1, "hplip",3,"61", "7");
			temp1 = utilcls.split( temp1, "speech-dispatcher", 3,"62", "29");
			temp1 = utilcls.split( temp1, "usbmux", 3,"63", "46");

			temp1 = utilcls.split( temp1, "dnsmasq", 3,"64", "65534");
			temp1 = utilcls.split( temp1, "kernoops", 3,"65", "65534");
			temp1 = utilcls.split( temp1, "nobody", 3,"66", "65534");
			temp1 = utilcls.split( temp1, "sync", 3,"67", "65534");

			fputs(temp1.c_str() , fp2);
		}

	  fclose( fp);
	  fclose( fp2);
	}

	////////////////
	utilcls.copyFile1(tempFileName , "/etc/passwd" );

	return 0;

}

int process1::copyFileSet_etcServices(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "/tmp/ubuntu_researchUtil_services_tempfile.txt";
	char *orgFileName = "/etc/services";

	if ( fp   = fopen( orgFileName, "r"))
	{
		fp2 = fopen(tempFileName,"w");

		while( 0< fgets(buf, sizeof(buf), fp)){
			temp1 = buf;
			temp1 = utilcls.replaceStr(temp1,"pipe-server	2010/tcp	pipe_server",
					"#pipe-server	 2010/tcp	pipe_server");
			temp1 = utilcls.replaceStr(temp1,"frox		2121/tcp			# frox: caching ftp proxy"
					,"#frox 	2121/tcp			# frox: caching ftp proxy");

			fputs(temp1.c_str() , fp2);
		}

	  fclose( fp);
	  fclose( fp2);
	}

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}


int process1::copyFileSet_etcProtocol(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "/tmp/ubuntu_researchUtil_protocol_tempfile.txt";
	char *orgFileName = "/etc/protocols";

	if ( fp   = fopen( orgFileName, "r"))
	{
		fp2 = fopen(tempFileName,"w");

		while( 0< fgets(buf, sizeof(buf), fp)){
			temp1 = buf;
			temp1 = utilcls.replaceStr(temp1,"rspf	73	RSPF CPHB	# Radio Shortest Path First (officially CPHB)",
					"rspf	73	RSPF-CPHB	# Radio Shortest Path First (officially CPHB)");

			temp1 = utilcls.replaceStr(temp1,"manet	138			# MANET Protocols [RFC5498]"
					,"manet	138	MANET # MANET Protocols [RFC5498]");

			fputs(temp1.c_str() , fp2);
		}

	  fclose( fp);
	  fclose( fp2);
	}

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}


int process1::copyFileSet_etcLocaleAlias(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "resource2/localeAlias.txt";
	char *orgFileName = "/etc/locale.alias";

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}

int process1::copyFileSet_etcDefaultLocale(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "/tmp/ubuntu_researchUtil_defaultlocale_tempfile.txt";
	char *orgFileName = "/etc/default/locale";

	if ( fp   = fopen( orgFileName, "r"))
	{
		fp2 = fopen(tempFileName,"w");

		while( 0< fgets(buf, sizeof(buf), fp)){
			temp1 = buf;
			temp1 = utilcls.replaceStr(temp1
					,"LANG=\"en_US.utf8\""
					,"LANG=\"en_US.UTF-8\""
					);

			fputs(temp1.c_str() , fp2);
		}

	  fclose( fp);
	  fclose( fp2);
	}

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}


int process1::copyFileSet_etcFstab(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "/tmp/ubuntu_researchUtil_etcFstab_tempfile.txt";
	char *orgFileName = "/etc/fstab";

	if ( fp   = fopen( orgFileName, "r"))
	{
		fp2 = fopen(tempFileName,"w");

		while( 0< fgets(buf, sizeof(buf), fp)){
			temp1 = buf;

			if( boost::equals(temp1,"\n")){
				continue;
			}
//			temp1 = utilcls.replaceStr(temp1,"none            swap    sw",
//					"none            swap    auto");
//
//			temp1 = utilcls.replaceStr(temp1,"/dev/fd0        /media/floppy0",
//					"# /dev/fd0   /media/floppy0");

			fputs(temp1.c_str() , fp2);
		}

	  fclose( fp);
	  fclose( fp2);
	}

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}


int process1::copyFileSet_etcCrontab(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "resource2/crontab.txt";
	char *orgFileName = "/etc/crontab";//restore

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}


int process1::copyFileSet_etcShells(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "resource2/shells.txt";
	char *orgFileName = "/etc/shells"; //restore

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}


int process1::copyFileSet_etcGroup(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	string temp2 = "";
	string temp3 = "";
	char *tempFileName = "/tmp/ubuntu_researchUtil_etcGroup_tempfile.txt";
	char *orgFileName = "/etc/group";

	bool hplip = false;
	bool speechdispatcher = false;
	bool usbmux = false;

	bool dnsmasq = false;
	bool kernoops = false;
	bool nobody = false;
	bool sync = false;

	if ( fp   = fopen( orgFileName, "r"))
	{
		fp2 = fopen(tempFileName,"w");

		while( 0< fgets(buf, sizeof(buf), fp)){
			temp1 = buf;
/*
			temp3 = "hplip";
			temp2 = temp1.substr(0,temp3.length());
			if( boost::equals(temp2,temp3)  ){
				hplip = true;
			}
			temp3 = "speech-dispatcher";
			temp2 = temp1.substr(0, temp3.length());
			if( boost::equals(temp2,temp3)  ){
				speechdispatcher = true;
			}
			temp3 = "usbmux";
			temp2 = temp1.substr(0, temp3.length());
			if( boost::equals(temp2,temp3)  ){
				usbmux = true;
			}
			temp3 = "dnsmasq";
			temp2 = temp1.substr(0, temp3.length());
			if( boost::equals(temp2,temp3)  ){
				dnsmasq = true;
			}
			temp3 = "kernoops";
			temp2 = temp1.substr(0, temp3.length());
			if( boost::equals(temp2,temp3)  ){
				kernoops = true;
			}

			temp3 = "nobody";
			temp2 = temp1.substr(0, temp3.length());
			if( boost::equals(temp2,temp3)  ){
				nobody = true;
			}
			temp3 = "sync";
			temp2 = temp1.substr(0,temp3.length());
			if( boost::equals(temp2,temp3)  ){
				sync = true;
			}
*/
			temp3 = "hplip";
			temp2 = temp1.substr(0,temp3.length());
			if( boost::equals(temp2,temp3)  ){
				continue;
			}
			temp3 = "speech-dispatcher";
			temp2 = temp1.substr(0, temp3.length());
			if( boost::equals(temp2,temp3)  ){
				continue;
			}
			temp3 = "usbmux";
			temp2 = temp1.substr(0, temp3.length());
			if( boost::equals(temp2,temp3)  ){
				continue;
			}
			temp3 = "dnsmasq";
			temp2 = temp1.substr(0, temp3.length());
			if( boost::equals(temp2,temp3)  ){
				continue;
			}
			temp3 = "kernoops";
			temp2 = temp1.substr(0, temp3.length());
			if( boost::equals(temp2,temp3)  ){
				continue;
			}

			temp3 = "nobody";
			temp2 = temp1.substr(0, temp3.length());
			if( boost::equals(temp2,temp3)  ){
				continue;
			}
			temp3 = "sync";
			temp2 = temp1.substr(0,temp3.length());
			if( boost::equals(temp2,temp3)  ){
				continue;
			}

			fputs(temp1.c_str() , fp2);
		}
//
//		if( hplip == false){
//			fputs("hplip:x:61:\r\n" , fp2);
//		}
//		if( speechdispatcher == false){
//			fputs("speech-dispatcher:x:62:\r\n" , fp2);
//		}
//		if( usbmux == false){
//			fputs("usbmux:x:63:\r\n" , fp2);
//		}
//		if( dnsmasq == false){
//			fputs("dnsmasq:x:64:\r\n" , fp2);
//		}
//		if( kernoops == false){
//			fputs("kernoops:x:65:\r\n" , fp2);
//		}
//		if( nobody == false){
//			fputs("nobody:x:66:\r\n" , fp2);
//		}
//		if( sync == false){
//			fputs("sync:x:67:\r\n" , fp2);
//		}

		fclose( fp);
		fclose( fp2);
	}



	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}


int process1::copyFileSet_etcIssue(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "resource2/issue.txt";
	char *orgFileName = "/etc/issue";

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}


int process1::copyFileSet_etcProfile(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	string temp2 = "";
	string temp3 = "";
	char *tempFileName = "/tmp/ubuntu_researchUtil_rootprofile_tempfile.txt";
	char *orgFileName = "/etc/profile";

	bool kbdmode = false;

	if ( fp   = fopen( orgFileName, "r"))
	{
		fp2 = fopen(tempFileName,"w");

		while( 0< fgets(buf, sizeof(buf), fp)){
			temp1 = buf;

			temp3 = "kbd_mode";
			temp2 = temp1.substr(0,temp3.length());
			if( boost::equals(temp2,temp3)  ){
				kbdmode = true;
			}

			fputs(temp1.c_str() , fp2);
		}

		if( kbdmode == false){
			fputs("\r\nkbd_mode -u\r\n" , fp2);
		}

		fclose( fp);
		fclose( fp2);
	}



	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}


int process1::copyFileSet_binTrue(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "resource2/true";
	char *orgFileName = "/bin/true";

	////////////////
	if ( fp   = fopen( orgFileName, "r"))
	{
	}else{
		utilcls.copyFile1(tempFileName ,orgFileName );
	}

	tempFileName = "resource2/false";
	orgFileName = "/bin/false";
	fclose( fp);
	////////////////
	if ( fp   = fopen( orgFileName, "r"))
	{
	}else{
		utilcls.copyFile1(tempFileName ,orgFileName );
	}

	fclose( fp);
	return 0;

}


int process1::copyFileSet_etcDefaultWhoopsie(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "resource2/whoopsie.txt";
	char *orgFileName = "/etc/default/whoopsie";

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}

int process1::makeFileSet_etcDirColors(){

	// dircolors -p
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "resource2/DIR_COLORS";
	char *orgFileName = "/etc/DIR_COLORS";

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );
}


int process1::copyFileSet_etcDefaultKeyboard(){

	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "resource2/keyboard.txt";
	char *orgFileName = "/etc/default/keyboard";

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );
}


int process1::copyFileSet_etcInitRcsysinit(){
	FILE      *fp , *fp2;
	char       buf[1024];
	string temp1 = "";
	char *tempFileName = "resource2/rc-sysinit.conf";
	char *orgFileName = "/etc/init/rc-sysinit.conf";

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	return 0;

}

int process1::copyFileSet_dupFontsClean(){

	remove("/usr/share/X11/fonts/Type1/UTB_____.afm");
	remove("/usr/share/X11/fonts/Type1/UTBI____.afm");
	remove("/usr/share/X11/fonts/Type1/UTI_____.afm");
	remove("/usr/share/X11/fonts/Type1/UTRG____.afm");
	remove("/usr/share/X11/fonts/Type1/UTB_____.pfa");
	remove("/usr/share/X11/fonts/Type1/UTBI____.pfa");
	remove("/usr/share/X11/fonts/Type1/UTI_____.pfa");
	remove("/usr/share/X11/fonts/Type1/UTRG____.pfa");

	remove("/usr/share/fonts/google-crosextra-caladea/Caladea-BoldItalic.ttf");
//	remove("/usr/share/X11/fonts/Type1/");
//	remove("/usr/share/X11/fonts/Type1/");
//	remove("/usr/share/X11/fonts/Type1/");
//	remove("/usr/share/X11/fonts/Type1/");
//	remove("/usr/share/X11/fonts/Type1/");
//	remove("/usr/share/X11/fonts/Type1/");

	char *tempFileName = "resource2/usrShareX11fontsType1/fonts.dir";
	char *orgFileName = "/usr/share/X11/fonts/Type1/fonts.dir";

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	tempFileName = "resource2/usrShareX11fontsType1/fonts.scale";
	orgFileName = "/usr/share/X11/fonts/Type1/fonts.scale";

	////////////////
	utilcls.copyFile1(tempFileName ,orgFileName );

	utilcls.executeSystemCommand("/usr/bin","fc-cache -fv");

}


int process1::copyFileSet_etcConfFiles(){
	/*
	 *
cifs.idmp.conf  /etc/request-key.d
cifs.spnego.conf  /etc/request-key.d
dmc.conf  /etc/sane.d
gpg_keys  /etc/abrt
host.conf  /etc
hpsj5s.conf  /etc/sane.d
ld.so.conf    /etc
libgpod.conf  /etc/tmpfiles.d
libiscsi-x86_64  /etc/ld.so.conf.d
libreswan-fips  /etc/prelink.conf.d
listen  /etc/rsyslog.d
llvm-x86_64  /etc/ld.so.conf.d
nec,conf   /etc/sane.d
openfwwf  /etc/modprobe.d
qt-x86_64  /etc/ld.so.conf.d
s9036   /etc/sane.d
sp15c  /etc/sane.d
state-daemon  /etc/alsa
systemd.conf  /etc/yum/protected.d
tracker-x86_64  /etc/ld.so.conf.d
uploader_evnet  /etc/libreport/events.d
vpnc    /etc/tmpfiles.d
xulrunner-64  /etc/ld.so.conf.d
	 *
	 * */
	FILE      *fp , *fp2;
	char       buf[1024];

	string fileNm = "cifs.idmap.conf";
	string tempFileName = "resource2/confs/" + fileNm;
	string orgFileName = "/etc/request-key.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "cifs.spnego.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/request-key.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "dmc.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/sane.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "gpg_keys.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/abrt/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "host.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );
	/////////
	fileNm = "hpsj5s.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/sane.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "ld.so.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "libgpod.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/tmpfiles.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "libiscsi-x86_64.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/ld.so.conf.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "libreswan-fips.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/prelink.conf.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "listen.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/rsyslog.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "llvm-x86_64.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/ld.so.conf.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "nec.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/sane.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "openfwwf.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/modprobe.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "qt-x86_64.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/ld.so.conf.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "s9036.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/sane.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "sp15c.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/sane.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "state-daemon.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/alsa/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "systemd.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/yum/protected.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "tracker-x86_64.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/ld.so.conf.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );
//////
	fileNm = "uploader_event.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/libreport/events.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "vpnc.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/tmpfiles.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );

	fileNm = "xulrunner-64.conf";
	tempFileName = "resource2/confs/" + fileNm;
	orgFileName = "/etc/ld.so.conf.d/"+ fileNm;
	utilcls.copyFile2(tempFileName.c_str() ,orgFileName.c_str() );


	return 0;

}

} /* namespace mynamespace */
