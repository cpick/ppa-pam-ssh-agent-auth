/* $OpenBSD: log.h,v 1.15 2006/08/18 09:13:25 deraadt Exp $ */

/*
 * Author: Tatu Ylonen <ylo@cs.hut.fi>
 * Copyright (c) 1995 Tatu Ylonen <ylo@cs.hut.fi>, Espoo, Finland
 *                    All rights reserved
 *
 * As far as I am concerned, the code I have written for this software
 * can be used freely for any purpose.  Any derived versions of this
 * software must be clearly marked as such, and if the derived work is
 * incompatible with the protocol description in the RFC file, it must be
 * called by a name other than "ssh" or "Secure Shell".
 */

#ifndef SSH_LOG_H
#define SSH_LOG_H
#include <stdarg.h>

/* Supported syslog facilities and levels. */
typedef enum {
	SYSLOG_FACILITY_DAEMON,
	SYSLOG_FACILITY_USER,
	SYSLOG_FACILITY_AUTH,
#ifdef LOG_AUTHPRIV
	SYSLOG_FACILITY_AUTHPRIV,
#endif
	SYSLOG_FACILITY_LOCAL0,
	SYSLOG_FACILITY_LOCAL1,
	SYSLOG_FACILITY_LOCAL2,
	SYSLOG_FACILITY_LOCAL3,
	SYSLOG_FACILITY_LOCAL4,
	SYSLOG_FACILITY_LOCAL5,
	SYSLOG_FACILITY_LOCAL6,
	SYSLOG_FACILITY_LOCAL7,
	SYSLOG_FACILITY_NOT_SET = -1
}       SyslogFacility;

typedef enum {
	SYSLOG_LEVEL_QUIET,
	SYSLOG_LEVEL_FATAL,
	SYSLOG_LEVEL_ERROR,
	SYSLOG_LEVEL_INFO,
	SYSLOG_LEVEL_VERBOSE,
	SYSLOG_LEVEL_DEBUG1,
	SYSLOG_LEVEL_DEBUG2,
	SYSLOG_LEVEL_DEBUG3,
	SYSLOG_LEVEL_NOT_SET = -1
}       LogLevel;

void     pamsshagentauth_log_init(char *, LogLevel, SyslogFacility, int);

SyslogFacility	pamsshagentauth_log_facility_number(char *);
LogLevel pamsshagentauth_log_level_number(char *);

void     pamsshagentauth_fatal(const char *, ...) __dead __attribute__((format(printf, 1, 2)));
void     pamsshagentauth_logerror(const char *, ...) __attribute__((format(printf, 1, 2)));
void     pamsshagentauth_sigdie(const char *, ...) __attribute__((format(printf, 1, 2)));
void     pamsshagentauth_logit(const char *, ...) __attribute__((format(printf, 1, 2)));
void     pamsshagentauth_verbose(const char *, ...) __attribute__((format(printf, 1, 2)));
void     pamsshagentauth_debug(const char *, ...) __attribute__((format(printf, 1, 2)));
void     pamsshagentauth_debug2(const char *, ...) __attribute__((format(printf, 1, 2)));
void     pamsshagentauth_debug3(const char *, ...) __attribute__((format(printf, 1, 2)));

void	 pamsshagentauth_do_log(LogLevel, const char *, va_list);
void	 pamsshagentauth_cleanup_exit(int) __dead;
#endif
