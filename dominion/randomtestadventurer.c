/*
randomtestadventurer.c
Tests the adventurer card from dominion.c
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define NUMBER_OF_TESTS 3

int main (int argc, char** argv) {


	printf("Starting test\n");
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int numSuccess = 0, numFail = 0;

	for(int i = 0; i < NUMBER_OF_TESTS; i++) {


		//printf("Here2\n");
		int numPlayers = rand() % 4;
		int player = 0;
		int seed = rand();
		struct gameState *g = malloc(sizeof(struct gameState));			
		initializeGame(numPlayers, k, seed, g);		



		g->deckCount[player] = rand() % MAX_DECK;						
		g->discardCount[player] = rand() % MAX_DECK;					
		int oldHand = g->handCount[player] = rand() % MAX_HAND;			
		int opponentHand = g->handCount[1] = rand() % MAX_HAND;
		int opponentDeck = g->deckCount[1] = rand() % MAX_DECK;


		printf("%d\n", g->handCount[player]);
		printf("%d\n", g->handCount[1]);	  
		int treasureStatus = 0;	
								
	
		for(int t = 0 ; t < g->handCount[player]; t++) {
			if((g->hand[player][t] == gold) || (g->hand[player][t] == silver) || (g->hand[player][t] == copper)) {
				treasureStatus++;
			}
		}
		cardEffect(adventurer, 1, 1, 1, g, 0, 0);						

		for(int j = 0 ; j < g->handCount[player]; j++) {
			if((g->hand[player][j] == gold) || (g->hand[player][j] == silver) || (g->hand[player][j] == copper)) {
				treasureStatus--;
			}
		}
		
		
		if(treasureStatus < 0 && oldHand + 1 == g->handCount[player] && opponentHand == g->handCount[1] && opponentDeck == g->deckCount[1]) 
			numSuccess++;											
		else {
			numFail++;
		}
		
		//printf("Pre-Free\n");
		free(g);
		//printf("Post-Free\n");
	}

	printf("Testing adventurer card...\nNumber of successful tests: %d. Number of failed tests: %d. Total number of tests: %d]\n", numSuccess, numFail, NUMBER_OF_TESTS);

	return 0;
}
