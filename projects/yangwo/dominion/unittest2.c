#include <stdlib.h>
#include <stdio.h>
#include "rngs.h"
#include "dominion.h"
#include "assert.h"

int main(){
	printf("Testing Shuffle function\n");
	struct gameState gs;

	int p = 0;
	gs.deckCount[p] = 4;
    gs.deck[p][0] = village;
    gs.deck[p][1] = silver;
    gs.deck[p][2] = adventurer;
    gs.deck[p][3] = smithy;

    shuffle(p, &gs);

    int cardsSet[MAX_DECK] = {0};

    for (int i=0 ; i<=3 ; i++)
    {
        cardsSet[gs.deck[p][i]] = 1;
    }

    if(cardsSet[village] && cardsSet[silver] && cardsSet[adventurer] && cardsSet[smithy] ){
    	printf("Shuffle function test successfull.\n");
    }
    else{
    	printf("Shuffle function test failed.\n");
    }
}