/*
 * Skeleton libary for MySQL.
 * A set of MySQL user defined functions (UDF) to [DESCRIPTION]
 *
 * Copyright (C) [YYYY YOUR NAME <YOU@EXAMPLE.COM>]
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

#include "mysqludf.h"

/* For Windows, define PACKAGE_STRING in the VS project */
#ifndef __WIN__
#include "config.h"
#endif

/* These must be right or mysqld will not find the symbol! */
#ifdef	__cplusplus
extern "C" {
#endif
	DLLEXP my_bool lib_mysqludf_skeleton_info_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
	DLLEXP void lib_mysqludf_skeleton_info_deinit(UDF_INIT *initid);
	/* For functions that return STRING or DECIMAL */ 
	DLLEXP char *lib_mysqludf_skeleton_info(UDF_INIT *initid, UDF_ARGS *args, char *result, unsigned long *length, char *is_null, char *error);

	/* For functions that return REAL */
	/* DLLEXP double lib_mysqludf_skeleton_info(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error); */
	/* For functions that return INTEGER */
	/* DLLEXP longlong lib_mysqludf_skeleton_info(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error); */

	/* If you are doing an Aggregate function you'll need these too */
	/* DLLEXP void lib_mysqludf_skeleton_info_clear( UDF_INIT* initid, char* is_null, char* is_error ); */
	/* DLLEXP void lib_mysqludf_skeleton_info_add( UDF_INIT* initid, UDF_ARGS* args, char* is_null, char* is_error ); */

#ifdef	__cplusplus
}
#endif


/*
 * Output the library version.
 * lib_mysqludf_skeleton_info()
 */

/* Sample data for aggregate function */
struct aggregate_data {
  ulonglong count;
};

/* The init function must be the name of the function with '_init' appended afterwards */
/* Return != 0 for an error and fill *message with an error messages if required
 * If successfull return 0 */
my_bool lib_mysqludf_skeleton_info_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
  /* for simple functions should validate the number and type of arguements are correct. */
  if (args->arg_count != 0)
  {
    strncpy(message,"wrong number of arguments: lib_mysqludf_skeleton_info() requires no arguments", MYSQL_ERRMSG_SIZE);
    return 1;
  }
	/*
	if (args->arg_type[0]!= INT_RESULT)
	{
		strncpy(message,"lib_mysqludf_skeleton_info_init() requires an int as parameter", MYSQL_ERRMSG_SIZE);
		return 1;
	}
	*/

	initid->maybe_null  = 0;    /* The result may be null */
	initid->decimals  = 4;    /* We want 4 decimals in the result */
	initid->max_length  = 20;   /* 6 digits + . + 10 decimals */

	/* For aggregate functions memory will need to be allocated for progress results.
			use the initd->ptr pointer for successive uses */
	/*
	struct aggregate_data *data;
	if (!(data = (struct aggregate_data*) malloc(sizeof(struct avgcost_data))))
	{
		strmov(message,"Couldn't allocate memory");
		return 1;
	}
	data->count = 0L;

	initid->ptr = data;
	*/
	return 0;
}

/* This is required to free any memory alloced in _init */
void lib_mysqludf_skeleton_info_deinit(UDF_INIT *initid)
{
	if (initid != NULL && initid->ptr != NULL) {
		free(initid->ptr);
		initid->ptr = NULL;
	}
}

/* For functions that return REAL */
/* double lib_mysqludf_skeleton_info(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error) */
/* For functions that return INTEGER */
/* longlong lib_mysqludf_skeleton_info(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error) */

/* For functions that return STRING or DECIMAL */ 
char* lib_mysqludf_skeleton_info(UDF_INIT *initid, UDF_ARGS *args, char* result, unsigned long* length,	char *is_null, char *error)
{
	strcpy(result, PACKAGE_STRING);
	*length = strlen(PACKAGE_STRING);
	return result;
}

/* clear is called between each group including before the first group in the aggregation */
void lib_mysqludf_skeleton_info_clear( UDF_INIT* initid, char* is_null, char* is_error )
{
	struct aggregate_data *data = (struct aggregate_data*) initid->ptr;
	data->count = 0L;
  /* Watch out for http://bugs.mysql.com/bug.php?id=38297 / MariaDB MDEV-7357 when using aggregation and WITH ROLLUP *
 *  you may need to allocation memory here in clear and deallocate in lib_mysqludf_skeleton_info. Check initid->ptr
 *  value first in case it gets fixed in future */
}

/* add is called for each row in the group */
void lib_mysqludf_skeleton_info_add( UDF_INIT* initid, UDF_ARGS* args, char* is_null, char* is_error )
{
	struct aggregate_data *data = (struct aggregate_data*) initid->ptr;
	if (args->args[0]) {
		data->count += *((longlong*)args->args[0]);
	}
}
