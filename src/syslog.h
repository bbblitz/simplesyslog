#ifndef __LOG_H__
#define __LOG_H__
//Logging priority
#define LOG_EMERG 0
#define LOG_ALERT 1
#define LOG_CRIT 2
#define LOG_ERR 3
#define LOG_WARNING 4
#define LOG_NOTICE 5
#define LOG_INFO 6
#define LOG_DEBUG 7

//Priority -> name
#define LOG_EMERG_MSG "[EMERGENCY]"
#define LOG_ALERT_MSG "[ALERT]"
#define LOG_CRIT_MSG "[CRITICAL]"
#define LOG_ERR_MSG "[ERROR]"
#define LOG_WARNING_MSG "[WARNING]"
#define LOG_NOTICE_MSG "[NOTICE]"
#define LOG_INFO_MSG "[INFO]"
#define LOG_DEBUG_MSG "[DEBUG]"

//Logging option (option)
#define LOG_ODELAY 0 //Block until the child process is done (if one was created) (default)
#define LOG_CONS 1 << 0 //Log to console if we fail to write
#define LOG_NDELAY 1 << 1 //Open the connection immediately
#define LOG_NOWAIT 1 << 2 //Don't wait for a child process that may have been created
#define LOG_PERROR 1 << 4 //Print to stderr as well
#define LOG_PID 1 << 5 //Include the PID with each message

//What program is doing the logging? (facility)
#define LOG_USER 0 //generic user-level messages
#define LOG_AUTH 1 //Security / authorization
#define LOG_AUTHPRIV 2 //^ but private
#define LOG_CRON 3 //cron and at
#define LOG_DAEMON 4 //system daemons catchall
#define LOG_FTP 5 //ftp daemon
#define LOG_KERN 6 //kernal messages
#define LOG_LOCAL0 7 //Reserved for local use (???)
#define LOG_LOCAL1 8 //Reserved for local use (???)
#define LOG_LOCAL2 9 //Reserved for local use (???)
#define LOG_LOCAL3 10 //Reserved for local use (???)
#define LOG_LOCAL4 11 //Reserved for local use (???)
#define LOG_LOCAL5 12 //Reserved for local use (???)
#define LOG_LOCAL6 13 //Reserved for local use (???)
#define LOG_LOCAL7 14 //Reserved for local use (???)
#define LOG_LPR 15 //line printer (???)
#define LOG_MAIL 16 //mail
#define LOG_NEWS 17 //for usenet or something
#define LOG_SYSLOG 18 //syslogd
#define LOG_UUCP 19 //UUCP

// Open a file for logging. ident is prepended to each message on each syslog call
void openlog(const char *ident, int option, int facility);

// Log something, priority is prepended BEFORE the ident
void syslog(int priority, const char *format, ...);

// Close the log
void closelog(void);
#endif
