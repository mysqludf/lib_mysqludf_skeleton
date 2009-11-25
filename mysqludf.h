/*
 * MySQL UDF includes and helper functions.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef MYSQLUDF_H_
#define MYSQLUDF_H_

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(WIN32)
#define DLLEXP __declspec(dllexport)
#else
#define DLLEXP
#endif

#ifdef STANDARD
/* STANDARD is defined, don't use any mysql functions */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef __WIN__
typedef unsigned __int64 ulonglong;	/* Microsofts 64 bit types */
typedef __int64 longlong;
#else
typedef unsigned long long ulonglong;
typedef long long longlong;
#endif /*__WIN__*/
#else
#include <my_global.h>
#include <my_sys.h>
#include <m_string.h>
#endif
#include <mysql.h>
#include <ctype.h>

#include "config.h"

char *strncpy_alloc(const char *str, unsigned long length);
void **ptr_calloc(size_t nelem, size_t elsize);
void ptr_free(void **ptr);
int strncmp_caseins(char *str1, char *str2, size_t num);
int charinstr(char *str, char c, size_t num);
char *copy_argname(char *att, unsigned long length);

#define TRIM_BACKQUOTE(fnull) (fnull+(int)(fnull[0]=='`'))		// Skip starting backquote
#define RETURN_ERR(msg) { strcpy(message, msg); return 1; }		// Set error message and return in %_init functions
#define ATTRIBUTE_COMPARE(i, str, len) (args->attribute_lengths[i] == len && strncmp_caseins(args->attributes[i], str, len) == 0)

#endif /* MYSQLUDF_H_ */
