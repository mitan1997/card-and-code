//
//  Hearts.h
//  Card Games
//

#ifndef __Card_Games__Hearts__
#define __Card_Games__Hearts__

#include <iostream>
#include "PokerDeck.h"
#include "PokerHand.h"
#include <list>

class Hearts
{
public:
   Hearts();
   static const size_t NUM_PLAYERS = 4;

private:
   typedef std::list<PokerCard> Pile;
   
   PokerHand *players;
   int *currPts;
   Pile centralPile;
   

public:
   // functional
   void game();

   // exception throwing
   class InvalidPlayerIndexException{};
};

#endif /* defined(__Card_Games__Hearts__) */
