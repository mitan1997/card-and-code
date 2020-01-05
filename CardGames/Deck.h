//
//  Deck.h
//  Card Games
//

#ifndef __Card_Games__Deck__
#define __Card_Games__Deck__

#include <iostream>
#include "Card.h"
#include <list>

template <
typename valType,
class CardObject = Card<valType>,
typename ContainerType = std::list<CardObject>
>
class Deck
{
protected:
   ContainerType mDeck;
   int numCards;

public:
   virtual void pop() = 0;
   virtual void clear() = 0;
};

#endif /* defined(__Card_Games__Deck__) */
