/*
randomtestcard1.c
Tests the Great Hall card from dominion.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define NUMBER_OF_TESTS 100

int main (int argc, char** argv) {


	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int numSuccess = 0, numFail = 0;

	for(int i = 0; i < NUMBER_OF_TESTS; i++) {

		struct gameState *g = malloc(sizeof(struct gameState));	
		int numPlayers = rand() % 4;
		int player = 0;
		int seed = rand();

		
		initializeGame(numPlayers, k, seed, g);		

		g->deckCount[player] = rand() % MAX_DECK;
        g->discardCount[player] = rand() % MAX_DECK;
        int originalHandCount = g->handCount[player] = rand() % MAX_HAND;
        int opponentHandCount = g->handCount[1] = rand() % MAX_HAND;
        int originalNumActions = g->numActions; 										
	
		cardEffect(great_hall, 1, 1, 1, g, 0, 0);						

		if (originalHandCount  == g->handCount[player] && originalNumActions + 1  == g->numActions && opponentHandCount  == g->handCount[1]){
            numSuccess++;
        }
        else{
        	numFail++;
        }
                        

		free(g);
	}

	printf("Testing Great Hall card...\nNumber of successful tests: %d. Number of failed tests: %d. Total number of tests: %d]\n", numSuccess, numFail, NUMBER_OF_TESTS);

	return 0;
}
