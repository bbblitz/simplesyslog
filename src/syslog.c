#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "syslog.h"

#define log_path "~/"

FILE *fd = NULL;
int o;
int f;
const char *ident;
void openlog(const char *it, int option, int facility){
	printf("Opening log\n");
	fd = fopen("log.txt","a+");
	printf("After opening, fd is %p\n",fd);
	o = option;
	f = facility;
	ident = it;
	printf("Finished opening log\n");
}

#define PROGRAM_NAME "???" //Default program name

void syslog(int priority, const char *format, ...){
	printf("in syslog, fd in now %p\n",fd);
	if(fd == NULL){
		openlog(NULL,LOG_DEBUG,LOG_USER);
	}
	char *s;
	switch(priority){
	case LOG_EMERG:
		s = LOG_EMERG_MSG;
		break;
	case LOG_ALERT:
		s = LOG_ALERT_MSG;
		break;
	case LOG_CRIT:
		s = LOG_CRIT_MSG;
		break;
	case LOG_ERR:
		s = LOG_ERR_MSG;
		break;
	case LOG_WARNING:
		s = LOG_WARNING_MSG;
		break;
	case LOG_NOTICE:
		s = LOG_NOTICE_MSG;
		break;
	case LOG_INFO:
		s = LOG_INFO_MSG;
		break;
	case LOG_DEBUG:
		s = LOG_DEBUG_MSG;
		break;
	}

	va_list arg_ptr;
	va_start(arg_ptr,format);
	/*printf("Printing ident\n");*/
	if(ident == NULL){
		fprintf(fd,"[%s]","???"); //This is supposed to print the program name
	}else{
		fprintf(fd,"[%s]",ident);
	}
	/*printf("Printing priority\n");*/
	fprintf(fd,"%s",s);
	/*printf("Printing formated text\n");*/
	vfprintf(fd,format,arg_ptr);
	va_end(arg_ptr);
}
void closelog(void){
	fclose(fd);
	fd = NULL;
}

