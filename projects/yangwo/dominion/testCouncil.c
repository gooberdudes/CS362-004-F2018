#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "rngs.h"

int main(){
  printf("Testing council room function\n");
  struct gameState gs;

  int k[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int success = 0;

  initializeGame(2, k, 2, &gs);
  gs.numBuys = 0;
  gs.deckCount[0] = 0;

  cardEffect(council_room, 1, 1, 1, gs, 0, 0);

  if(gs.deckCount[0] != 4){
    printf("Test failure: Incorrect number of cards drawn.\n");
  }

  if(!success){
    printf("Test failed.\n");
  }
  else{
    printf("Test successful\n");
  }
  return 0;
}