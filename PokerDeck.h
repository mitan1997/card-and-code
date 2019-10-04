//
//  PokerDeck.h
//  Card Games
//

#ifndef __Card_Games__PokerDeck__
#define __Card_Games__PokerDeck__

#include <iostream>
#include <list>
#include <vector>
#include "Deck.h"
#include "PokerCard.h"
#include "PokerHand.h"

class PokerDeck : public Deck<int, PokerCard, std::list<PokerCard>>
{
public:
   virtual void pop();
   void push(const PokerCard &card);
   bool init(int numPacks = 1);
   virtual void clear();
   bool empty() const {return this->mDeck.empty();}
   void shuffle();
   const PokerCard & top() const;
   void give(PokerHand &hand);

   static const int NUM_CARDS_PER_PACK =
   PokerCard::MAX_SUIT_INDEX * PokerCard::MAX_FACE_INDEX;

   PokerDeck(int numPacks = 1);
   PokerDeck & operator=(const PokerDeck &rhs);

   class EmptyDeckException{};
};

#endif /* defined(__Card_Games__PokerDeck__) */
