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

		int numPlayers = rand() % 4;
		int player = 0;
		int seed = rand();

		struct gameState *g = malloc(sizeof(struct gameState));			
		int status = initializeGame(numPlayers, k, seed, g);		

		g->deckCount[player] = rand() % MAX_DECK;						
		g->discardCount[player] = rand() % MAX_DECK;					
		int oldHand = g->handCount[player] = rand() % MAX_HAND;			
		int opponentHand = g->handCount[1] = rand() % MAX_HAND;
		int opponentDeck = g->deckCount[1] = rand() % MAX_DECK;
		int checkStatus = 0;											//variable to track if cards added were treasure cards or not 
	
		for(int t = 0 ; t < g->handCount[player]; t++) {
			if((g->hand[player][t] == gold) || (g->hand[player][t] == silver) || (g->hand[player][t] == copper)) {
				checkStatus++;
			}
		}
		cardEffect(adventurer, 1, 1, 1, g, 0, 0);						//play the card

	
		for(int j = 0 ; j < g->handCount[player]; j++) {
			if((g->hand[player][j] == gold) || (g->hand[player][j] == silver) || (g->hand[player][j] == copper)) {
				checkStatus--;
			}
		}

		if(checkStatus < 0 && oldHand + 1 == g->handCount[player] && opponentHand == g->handCount[1] && opponentDeck == g->deckCount[1]) 
			numSuccess++;											//if cards were added, and were treasure cards, then this test was successful
		else 
			numFail++;

		free(g);
	}
	printf("Testing adventurer card...");
	printf("\nThere were %d successful adventurer card plays, and %d failures [out of %d games]\n\n", numSuccess, numFail, NUMBER_OF_TESTS);

	return 0;
}
