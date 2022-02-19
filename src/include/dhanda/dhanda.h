#ifndef _DHANDA_H_
#define _DHANDA_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include <dhanda/list.h>

typedef struct dhanda {
	FILE *party_fp;
	FILE *txn_fp;
} dhanda;

void dhanda_init_app(dhanda *app);


#endif
