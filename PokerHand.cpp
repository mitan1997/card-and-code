//
//  PokerHand.cpp
//  Card Games
//

#include "PokerHand.h"

PokerHand::PokerHand(int numCards)
{
   mHand.reserve(numCards);
   sort();
}

template <typename ContainerType>
PokerHand::PokerHand(const ContainerType &cards)
{
   typename ContainerType::const_iterator iter = cards.begin();
   mHand.reserve(cards.size());

   for (iter; iter != cards.end(); iter++)
      addCard(*iter);
}

const PokerCard & PokerHand::operator[](int index) const
{
   if (index < 0 || index >= mHand.size())
      throw InvalidIndexException();

   return mHand[index];
}

PokerCard & PokerHand::operator[](int index)
{
   if (index < 0 || index >= mHand.size())
      throw InvalidIndexException();

   return mHand[index];
}

std::ostream & operator<<(std::ostream &ostrm, const PokerHand &hand)
{
   if (hand.isEmpty())
   {
      ostrm << "Hand is empty" << endl;
      return ostrm;
   }
   
   typename std::vector<PokerCard>::const_iterator iter = hand.mHand.begin();
   for (iter; iter != hand.mHand.end(); iter++)
      std::cout << *iter << " ";
   std::cout << std::endl;
   return ostrm;
}

const PokerCard & PokerHand::front() const
{
   if (mHand.empty())
      throw EmptyHandException();
   return mHand[0];
}

const PokerCard & PokerHand::back() const
{
   if (mHand.empty())
      throw EmptyHandException();
   return mHand[mHand.size() - 1];
}

bool PokerHand::addCard(const PokerCard &card)
{
   if (!card.validCard())
      return false;

   mHand.push_back(card);
   return true;
}

PokerCard & PokerHand::play(const PokerCard &card)
{
   if (mHand.empty())
      throw EmptyHandException();
   
   for (int i = 0; i < mHand.size(); i++)
      if (mHand[i] == card)
         return play(i);

   throw InvalidCardException();
}

PokerCard & PokerHand::play(int index)
{
   if (mHand.empty())
      throw EmptyHandException();
   
   if (index < 0 || index >= mHand.size())
      throw InvalidIndexException();

   for (int i = index; i < mHand.size() - 1; i++)
      PokerCard::cardSwap(mHand[i], mHand[i + 1]);

   PokerCard retCard(mHand.back());
   mHand.pop_back();
   return retCard;
}

template <typename Comparator>
void PokerHand::sort()
{
   // insertion sort
   Comparator __compare;
   for (int i = 1; i < mHand.size(); i++)
      for (int j = i; j > 0 && __compare(mHand[j], mHand[j - 1]); j--)
         PokerCard::cardSwap(mHand[j], mHand[j - 1]);
}

struct PokerHand::FaceAscending
{
   bool operator()(const PokerCard &lhs, const PokerCard &rhs)
   {
      return (lhs.getFace() == rhs.getFace())?
      (lhs.getSuit() < rhs.getSuit()) : (lhs.getFace() < rhs.getFace());
   }
};

struct PokerHand::SuitAscending
{   
   bool operator()(const PokerCard &lhs, const PokerCard &rhs)
   {
      return (lhs.getSuit() == rhs.getSuit())?
      (lhs.getFace() < rhs.getFace()) : (lhs.getSuit() < rhs.getSuit());
   }
};


