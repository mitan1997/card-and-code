//
//  PokerCard.cpp
//  Card Games
//

#include "PokerCard.h"

const std::string PokerCard::POSSIBLE_FACE[] =
{"NA", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
const std::string PokerCard::POSSIBLE_SUIT[] = {"NA", "♦", "♣", "♥", "♠"};

PokerCard::PokerCard(int faceIndex, int suitIndex)
{
   if (!setFace(faceIndex))
      val1 = INVALID_INDEX;
   if (!setSuit(suitIndex))
      suit = NA;
}

PokerCard::PokerCard(int faceIndex, Suit st)
{
   if (!setFace(faceIndex))
      val1 = INVALID_INDEX;
   if (!setSuit(st))
      suit = NA;
}

PokerCard::PokerCard(const PokerCard &card)
{
   this->val1 = card.val1;
   this->suit = card.suit;
}

PokerCard & PokerCard::operator=(const PokerCard &rhs)
{
   val1 = rhs.val1;
   suit = rhs.suit;
   return *this;
}

bool PokerCard::operator==(const PokerCard &rhs) const
{
   return (val1 == rhs.val1 && suit == rhs.suit);
}

void PokerCard::cardSwap(PokerCard &card1, PokerCard &card2)
{
   PokerCard tmp = card2;
   card2 = card1;
   card1 = tmp;
}

bool PokerCard::setSuit(int suitIndex)
{
   if (!validSuit(suitIndex))
      return false;

   suit = static_cast<Suit>(suitIndex);
   return true;
}

bool PokerCard::setSuit(Suit st)
{
   if (st == NA)
      return false;

   suit = st;
   return true;
}

bool PokerCard::setFace(int faceIndex)
{
   if (!validFace(faceIndex))
      return false;

   val1 = faceIndex;
   return true;
}

std::string PokerCard::toString() const
{
   if (!validFace(val1))
      throw InvalidIndexException();

   return (POSSIBLE_FACE[val1] + POSSIBLE_SUIT[static_cast<int>(suit)]);
}

std::ostream & operator<<(std::ostream &ostrm, const PokerCard &card)
{
   if (!card.validCard())
      throw PokerCard::InvalidIndexException();
   ostrm << card.toString();
   return ostrm;
}

std::string PokerCard::suitToString(Suit st) const
{
   return POSSIBLE_SUIT[static_cast<int>(st)];
}

std::string PokerCard::suitToString(int index) const
{
   if (!validSuit(index))
      throw InvalidIndexException();

   return POSSIBLE_SUIT[index];
}

PokerCard randCard()
{
   return PokerCard(rand() % PokerCard::MAX_FACE_INDEX + 1,
                    rand() % PokerCard::MAX_SUIT_INDEX + 1);
}

