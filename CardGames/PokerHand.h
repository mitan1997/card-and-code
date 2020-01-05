//
//  PokerHand.h
//  Card Games
//

#ifndef __Card_Games__PokerHand__
#define __Card_Games__PokerHand__

#include <iostream>
#include "PokerCard.h"
#include <vector>
#include <algorithm>

class PokerHand
{
private:
   std::vector<PokerCard> mHand;

public:
   struct FaceAscending;
   
   struct SuitAscending;
   
   static const int DFLT_NUM_CARDS = 7;
   
   PokerHand(int numCards = DFLT_NUM_CARDS);
   PokerHand(const PokerCard &card) {addCard(card);}
   template <typename ContainerType = std::vector<PokerCard>>
   PokerHand(const ContainerType &cards);
   
   // accessors
   size_t getNumCards() const {return mHand.size();}
   size_t size() const {return mHand.size();}
   PokerCard & operator[](int index);
   const PokerCard & operator[](int index) const;
   friend std::ostream & operator<<(std::ostream &ostrm, const PokerHand &hand);
   const PokerCard & front() const;
   const PokerCard & back() const;
   bool isEmpty() const {return mHand.empty();}

   bool addCard(const PokerCard &card);

   PokerCard & play(const PokerCard &card = PokerCard(0,0));
   PokerCard & play(int cardIndex);
   
   template <typename Comparator = SuitAscending>
   void sort();

   // exception throwing
   class InvalidIndexException{};
   class InvalidCardException{};
   class EmptyHandException{};
};



#endif /* defined(__Card_Games__PokerHand__) */
