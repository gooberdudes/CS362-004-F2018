#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"

int main() {
	printf("Testing Outpost Card..\n");
	int numActions, numHand, numDeck;
	struct gameState gs;
	int *k = kingdomCards(adventurer, minion, smithy, cutpurse, tribute, baron, mine, embargo, outpost, gardens);

	int oppNumHand, oppNumDeck;
	int r = 34;
	initializeGame(2, k, r, &gs);


	gs.whoseTurn = 0;
	gs.deckCount[0] = 3;
	gs.handCount[1] = 1;
	gs.deckCount[1] = 1;
	oppNumDeck = gs.deckCount[1];
	oppNumHand = gs.handCount[1];
	gs.hand[0][0] = outpost;
	gs.hand[0][1] = adventurer;
	gs.coins = 0;
	gs.numBuys = 1;

	numActions = gs.numActions;
	numDeck = gs.deckCount[0];
	numHand = gs.handCount[0];

	cardEffect(outpost, adventurer, 0, 0, &gs, 0, NULL);
	int success = 1; 

	if(gs.handCount[0] == numHand - 1 ){
		printf("Removed 1 card from players hand..\n");
	}
	else{
		printf("ERROR: Incorrect number of cards added to hand..\n");
		success = 0;
	}

	if(numActions == gs.numActions){
		printf("Actions unchanged correctly..\n");

	}
	else{
		printf("ERROR: Number of actions changed...\n");
		success = 0;
	}
	if(success == 1){ printf("Outpost: Tests passed successfully..\n");}
}