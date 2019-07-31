#ifndef _DB_H
#define _DB_H

#include <people.h>

int people_insertdb(people_t *p);
int people_delete_db(people_t *p);
int people_updatedb(people_t *p);

#endif
