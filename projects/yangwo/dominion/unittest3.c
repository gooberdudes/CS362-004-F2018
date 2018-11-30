#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"

int main(){
	printf("Testing isGameOver function\n");
	struct gameState gs;

	int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	initializeGame(2, k, 2, &gs);
	gs.supplyCount[province] = 3;
	int success = 1;

	if(isGameOver(&gs) != 0){
		printf("Test failure: Game ended before it shold have.\n");
		success = 0;
	}
	gs.supplyCount[province] = 0;
	if(isGameOver(&gs) != 1){
		printf("Test failure: Game didn't end when it should have.");
		success = 0;
	}

	if(!success){
		printf("Test failed.\n");
	}
	else{
		printf("Test successful\n");
	}
	return 0;
}