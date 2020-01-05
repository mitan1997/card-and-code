//
//  PokerCard.h
//  Card Games
//

#ifndef __Card_Games__PokerCard__
#define __Card_Games__PokerCard__

#include "Card.h"
#include <string>
#include <iostream>

using namespace std;

class PokerCard : public Card<int>
{
public:
   enum Suit{NA, diamonds, clubs, hearts, spades};
   static const int MAX_FACE_INDEX = 13;
   static const int MIN_FACE_INDEX = 1;
   static const int MIN_SUIT_INDEX = 1;
   static const int MAX_SUIT_INDEX = 4;
   static const int CARDS_PER_PACK = MAX_FACE_INDEX * MAX_SUIT_INDEX;
   static const int INVALID_INDEX = 0;
   static const std::string POSSIBLE_FACE[];
   static const std::string POSSIBLE_SUIT[];

   class InvalidIndexException{};
   
protected:
   Suit suit;
   virtual bool setVal1(int faceIndex) {return setFace(faceIndex);}
   virtual int getVal1() const {return getFace();}

public:
   PokerCard(int faceIndex = INVALID_INDEX, int suitIndex = INVALID_INDEX);
   PokerCard(int faceIndex, Suit st);
   PokerCard(const PokerCard &card);
   PokerCard & operator=(const PokerCard &rhs);
   bool operator==(const PokerCard &rhs) const;

   static void cardSwap(PokerCard &card1, PokerCard &card2);
   
   friend std::ostream & operator<<(std::ostream & ostrm, const PokerCard &card);
   std::string suitToString(Suit st) const;
   std::string suitToString(int suitIndex) const;
   std::string toString() const;
   bool validCard() const {return validFace(val1) && validSuit(suit);}

   bool setSuit(int index);
   bool setSuit(Suit st);
   bool setFace(int index);
   
   Suit getSuit() const {return suit;}
   virtual int getFace() const {return this->val1;}

private:
   static bool validFace(int faceIndex) {return !(faceIndex < MIN_FACE_INDEX || faceIndex > MAX_FACE_INDEX);}
   static bool validSuit(int suitIndex) {return !(suitIndex < MIN_SUIT_INDEX || suitIndex > MAX_SUIT_INDEX);}
   static bool validSuit(Suit st) {return !(st == NA);}
};

PokerCard randCard();

#endif /* defined(__Card_Games__PokerCard__) */
