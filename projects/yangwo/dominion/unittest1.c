#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>

int main(){
	printf("Testing supplyCount function\n");
	struct gameState gs;

	gs.supplyCount[silver] = 4;
	if(supplyCount(silver, &gs) == 4){
		printf("supplyCount Unit Test passed.\n");
	}
	return 0;
}