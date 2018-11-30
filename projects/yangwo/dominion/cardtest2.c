#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"

int main() {
	printf("Testing Village Card..\n");
	int origActions;
	struct gameState gs;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	int r = 3;
	initializeGame(2, k, r, &gs);

	origActions = gs.numActions;
	cardEffect(village, 1, 1, 1, &gs, 0, 0);	
	int success = 1; 

	if(gs.numActions == origActions + 2){
		printf("2 actions successfully added to numActions..\n");
	}
	else{
		printf("ERROR: Incorrect number of cards added to hand..\n");
		success = 0;
	}
	
	if(!success){
		printf("TEST FAILED.\n");
	}
	else{
		printf("Village: All tests successfully completed.\n");
	}
}