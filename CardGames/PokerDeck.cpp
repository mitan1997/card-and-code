//
//  PokerDeck.cpp
//  Card Games
//

#include "PokerDeck.h"

PokerDeck::PokerDeck(int numPacks)
{
   if (!init(numPacks))
      init(1);
}

bool PokerDeck::init(int numPacks)
{
   if (numPacks < 0)
      return false;
   
   this->mDeck.clear();
   for (int i = 0; i < numPacks * NUM_CARDS_PER_PACK; i++)
      this->mDeck.push_back(PokerCard(i % PokerCard::MAX_FACE_INDEX + 1,
                                      i % PokerCard::MAX_SUIT_INDEX + 1));
   numCards = NUM_CARDS_PER_PACK * numPacks;
   shuffle();
   return true;
}

const PokerCard & PokerDeck::top() const
{
   if (this->mDeck.empty())
      throw EmptyDeckException();
   return this->mDeck.back();
}

void PokerDeck::give(PokerHand &hand)
{
   hand.addCard(this->top());
   this->pop();
}

void PokerDeck::pop()
{
   if (numCards <= 0)
      return;
   this->mDeck.pop_back();
   numCards--;
}

void PokerDeck::push(const PokerCard &card)
{
   if (!card.validCard())
      throw PokerCard::InvalidIndexException();

   this->mDeck.push_back(card);
}

void PokerDeck::clear()
{
   while (!this->mDeck.empty())
      pop();
}

PokerDeck & PokerDeck::operator=(const PokerDeck &other)
{
   this->clear();
   this->numCards = other.numCards;
   typename std::list<PokerCard>::const_iterator otherIter =
   other.mDeck.begin();

   for (otherIter; otherIter != other.mDeck.end(); otherIter++)
      this->mDeck.push_back(*otherIter);
   return *this;
}

void PokerDeck::shuffle()
{
   const int SWAP_CHANCE = 50;
   typename std::list<PokerCard>::iterator iter = this->mDeck.begin();
   typename std::list<PokerCard>::iterator iter2;

   // quadratic time complexity for shuffling algorithm
   for (iter; iter != this->mDeck.end(); iter++)
      for (iter2 = this->mDeck.begin(); iter2 != this->mDeck.end(); iter2++)
         if (rand() % 100 < SWAP_CHANCE)
            PokerCard::cardSwap(*iter, *iter2);
}
