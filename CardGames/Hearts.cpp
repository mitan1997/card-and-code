//
//  Hearts.cpp
//  Card Games
//

#include "Hearts.h"

Hearts::Hearts()
{
   players = new PokerHand[NUM_PLAYERS];
   
   PokerDeck deckForPlayers;
   for (int i = 0; !deckForPlayers.empty(); i++)
      deckForPlayers.give(players[i % NUM_PLAYERS]);
   
   currPts = new int[NUM_PLAYERS];
}

void Hearts::game()
{
   if (players == nullptr)
      return;

   const int NUM_ROUNDS = PokerCard::CARDS_PER_PACK / NUM_PLAYERS;
   PokerCard::Suit currSuit;
   bool heartsBroken = false;
   int firstPlayer = 0; // set default first player for first round
   
   for (int round = 0; round < NUM_ROUNDS; round++)
   {
      
   }
}


