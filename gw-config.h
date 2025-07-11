/* gw-config.h.  Generated from gw-config.h.in by configure.  */
/* ==================================================================== 
 * The Kannel Software License, Version 1.0 
 * 
 * Copyright (c) 2001-2009 Kannel Group  
 * Copyright (c) 1998-2001 WapIT Ltd.   
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in 
 *    the documentation and/or other materials provided with the 
 *    distribution. 
 * 
 * 3. The end-user documentation included with the redistribution, 
 *    if any, must include the following acknowledgment: 
 *       "This product includes software developed by the 
 *        Kannel Group (http://www.kannel.org/)." 
 *    Alternately, this acknowledgment may appear in the software itself, 
 *    if and wherever such third-party acknowledgments normally appear. 
 * 
 * 4. The names "Kannel" and "Kannel Group" must not be used to 
 *    endorse or promote products derived from this software without 
 *    prior written permission. For written permission, please  
 *    contact org@kannel.org. 
 * 
 * 5. Products derived from this software may not be called "Kannel", 
 *    nor may "Kannel" appear in their name, without prior written 
 *    permission of the Kannel Group. 
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES 
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED.  IN NO EVENT SHALL THE KANNEL GROUP OR ITS CONTRIBUTORS 
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT  
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 * ==================================================================== 
 * 
 * This software consists of voluntary contributions made by many 
 * individuals on behalf of the Kannel Group.  For more information on  
 * the Kannel Group, please see <http://www.kannel.org/>. 
 * 
 * Portions of this software are based upon software originally written at  
 * WapIT Ltd., Helsinki, Finland for the Kannel project.  
 */ 

#ifndef CONFIG_H
#define CONFIG_H

/* Define one of these depending on which malloc wrapper you want to use. */
#define USE_GWMEM_NATIVE 1
/* #undef USE_GWMEM_CHECK */
/* #undef USE_GWMEM_SLOW */

/* Define if you want information about lock collisions to be collected.
 * These are useful for finding performance bottlenecks. */
/* #undef MUTEX_STATS */

/* Define if you want log file timestamps in localtime instead of GMT. */
#define LOG_TIMESTAMP_LOCALTIME 1

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if your compiler supports the __func__ magic symbol. This is
   part of C99. */
#define HAVE___FUNC__ 1

/* Define if your compiler supports the __FUNCTION__ magic symbol. */
#define HAVE___FUNCTION__ 1

/* Make sure __func__ does something useful. */
#if defined(HAVE___FUNC__)
    /* Nothing to do. Life is so wonderful. */
#elif defined(HAVE___FUNCTION__)
    #define __func__ __FUNCTION__
#else
    #define __func__ "unknown"
#endif

/* Define if you have getopt.h. */
#define HAVE_GETOPT_H 1

/* Define if you have getopt(3). */
/* #undef HAVE_GETOPT */

/* Define if you have a declaration for getopt(3) in <stdio.h>. */
/* #undef HAVE_GETOPT_IN_STDIO_H */

/* Define if you have a declaration for getopt(3) in <unistd.h>. */
#define HAVE_GETOPT_IN_UNISTD_H 1

/* Define if you have getopt_long(3). */
#define HAVE_GETOPT_LONG 1

/* Define gateway name */
#define GW_NAME "Kannel"

/* Define which version we use */
#define GW_VERSION "svn-r"

/* WMLScript debugging. */
/* #undef WS_DEBUG */

/* Define if you have the gettimeofday function.  */
#define HAVE_GETTIMEOFDAY 1

/* Define if you have the select function.  */
#define HAVE_SELECT 1

/* Define if you have the socket function.  */
#define HAVE_SOCKET 1

/* Define if you have the localtime_r function.  */
#define HAVE_LOCALTIME_R 1

/* Define if you have the gmtime_r function.  */
#define HAVE_GMTIME_R 1

/* Define if you have the backtrace function. */
#define HAVE_BACKTRACE 1

/* Define if you have the srandom function. */
#define HAVE_SRANDOM 1

/* Define if you have the <fcntl.h> header file.  */
/* #undef HAVE_FCNTL_H */

/* Define if you have the <pthread.h> header file.  */
#define HAVE_PTHREAD_H 1

/* Define if you have the <sys/ioctl.h> header file.  */
#define HAVE_SYS_IOCTL_H 1

/* Define if you have the <sys/types.h> header file.  */
#define HAVE_SYS_TYPES_H 1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H 1

/* Define if you have the <sys/poll.h> header file.  */
#define HAVE_SYS_POLL_H 1

/* Define if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define if you have the <sys/socket.h> header file. */
#define HAVE_SYS_SOCKET_H 1

/* Define if you have the <sys/sockio.h> header file. */
/* #undef HAVE_SYS_SOCKIO_H */

/* Define if you have the <net/if.h> header file. */
#define HAVE_NET_IF_H 1

/* Define if you have the <netinet/in.h> header file. */
#define HAVE_NETINET_IN_H 1

/* Define if you have the m library (-lm).  */
#define HAVE_LIBM 1

/* Define if you have the nsl library (-lnsl).  */
/* #undef HAVE_LIBNSL */

/* Define if you have the pthread library (-lpthread).  */
/* #undef HAVE_LIBPTHREAD */

/* Define if you have the socket library (-lsocket).  */
/* #undef HAVE_LIBSOCKET */

/* Define if you have the xml library (-lxml).  */
/* #undef HAVE_LIBXML */

/* Define if you have the z library (-lz).  */
/* #undef HAVE_LIBZ */

/* Define if there is a socklen_t in <sys/socket.h> */
#define HAVE_SOCKLEN_T 1

/* Define if the PAM headers are on the local machine */
/* #undef HAVE_SECURITY_PAM_APPL_H */

/* Define if you want to turn off assertion checking */
/* #undef NO_GWASSERT */

/* Define if you have <syslog.h>.  */
#define HAVE_SYSLOG_H 1

/* Defines for iconv.  */
#define HAVE_ICONV 1
#define ICONV_CONST 

/* Define if you have <execinfo.h>. */
#define HAVE_EXECINFO_H 1

/* Define if you have and want to use the ssl library (-lssl) */
/* #undef HAVE_LIBSSL */

/* Defined if we're using OpenSSL WTLS */
/* #undef HAVE_WTLS_OPENSSL */

/* Define if you have and want to use the FreeTDS ct-lib */
/* #undef HAVE_MSSQL */

/* Define if you have and want to use the MySQL client library (-lmysqlclient) */
/* #undef HAVE_MYSQL */

/* Define if you have and want to use the sdb client library (-lsdb) */
/* #undef HAVE_SDB */

/* Define if you have and want to use the OCI library */
/* #undef HAVE_ORACLE */

/* Define if you have and want to use the SQLite database library (-lsqlite) */
/* #undef HAVE_SQLITE */

/* Define if you have and want to use the SQLite3 database library (-lsqlite3) */
/* #undef HAVE_SQLITE3 */

/* Define version of used libSDB */
/* #undef LIBSDB_VERSION */

/* Define if you have and want to use the PostgreSQL dlr routines (-lpq) */
/* #undef HAVE_PGSQL */

/* Define if you want to have cookie support for the WSP */
#define ENABLE_COOKIES 1

/* Define if you want to have HTTP/1.1 keep-alive support */
#define USE_KEEPALIVE 1

/* Define not to include the WAP gateway parts */
/* #undef NO_WAP */

/* Define not to include the SMS gateway parts */
/* #undef NO_SMS */

/* Define for various gethostbyname_r functions */
#define HAVE_FUNC_GETHOSTBYNAME_R_6 1
/* #undef HAVE_FUNC_GETHOSTBYNAME_R_5 */
/* #undef HAVE_FUNC_GETHOSTBYNAME_R_3 */

/* Define if you have and want to use POSIX regular expressions */
#define HAVE_REGEX 1

/* Define if you have and want to use PCRE (Perl compatible regular expressions) */
/* #undef HAVE_PCRE */

/* Define version of used libpcre */
/* #undef LIBPCRE_VERSION */

/* Define if you have pthread_spinlock_t type and spinlock support. */
#define HAVE_PTHREAD_SPINLOCK_T 1

/* Define if you have pthread_rwlock_t type and reader/writer lock support. */
#define HAVE_PTHREAD_RWLOCK 1

/* Define if you have working semaphore (sem_t). */
#define HAVE_SEMAPHORE 1

/* If we're using GCC, we can get it to check format function arguments. */
#ifdef __GNUC__
    #define PRINTFLIKE(a,b) __attribute__((format(printf, a, b)))
#else
    #define PRINTFLIKE(a, b)
#endif
                     
/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

#endif
