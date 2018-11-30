#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"

int main() {
	printf("Testing Adventurer Card..\n");
	int numActions, numHand, numDeck;
	struct gameState gs;
	int *k = kingdomCards(adventurer, minion, smithy, cutpurse, tribute, baron, mine, embargo, outpost, gardens);

	int oppNumHand, oppNumDeck;
	int r = 34;
	initializeGame(2, k, r, &gs);


	gs.whoseTurn = 1;
	gs.hand[1][0] = adventurer;
	gs.deckCount[1] = 2;
	oppNumDeck = gs.deckCount[1];
	oppNumHand = gs.handCount[1];

	endTurn(&gs);

	gs.hand[0][0] = adventurer;
	gs.deck[0][0] = copper;
	gs.deck[0][1] = copper;
	gs.deckCount[0] = 2;

	numActions = gs.numActions;
	numDeck = gs.deckCount[0];
	numHand = gs.handCount[0];

	cardEffect(adventurer, 1, 1, 1, &gs, 0, NULL);
	int success = 1; 

	if(gs.handCount[0] == numHand + 2){
		printf("2 cards successfully added to hand..\n");
	}
	else{
		printf("ERROR: Incorrect number of cards added to hand..\n");
		success = 0;
	}

	if(fullDeckCount(0,0,&gs) < numDeck){
		printf("Deck size decreased properly..\n");

	}
	else{
		printf("ERROR: Incorrect deck count after card played..\n");
		success = 0;
	}

	if(numActions == gs.numActions){
		printf("numActions correctly remains unchanged..\n");
	}
	else{
		printf("ERROR: numActions changed incorrectly..\n");
		success = 0;
	}

	if(oppNumDeck == gs.deckCount[1]){
		printf("Opponents deck correctly unchanged..\n");
	}
	else{
		printf("ERROR: Opponents deck was changed!\n");
		success = 0;
	}

	if(oppNumHand == gs.handCount[1]){
		printf("Opponent's hand correctly remains unchanged..\n");
	}
	else{
		printf("ERROR: Opponent's hand was changed!\n");
		success = 0;
	}
	
	if(!success){
		printf("TEST FAILED.\n");
	}
	else{
		printf("Adventurer: All tests successfully completed.\n");
	}
}