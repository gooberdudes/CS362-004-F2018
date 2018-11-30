#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"

int main(){
	printf("Testing buyCard function\n");
	struct gameState gs;

	int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	initializeGame(2, k, 2, &gs);


	gs.numBuys = 0;
	int res = buyCard(9, &gs);

	if(res != -1){
		printf("Test failure: Allowed buying of a card when there are no buys.");
		success = 0;
	}

	gs.coins = 0;

	res = buyCard(3, &gs);

	if(res != -1){
		printf("Test failure: Allowed buying of a card when there are no coins.");
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