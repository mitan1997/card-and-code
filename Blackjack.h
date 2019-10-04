//
//  Blackjack.h
//  Card Games
//

#ifndef __Card_Games__Blackjack__
#define __Card_Games__Blackjack__

#include <iostream>
#include "Pokerhand.h"
#include "PokerDeck.h"

class Blackjack
{
public:
   Blackjack(int numPlayers = MIN_PLAYERS);
   Blackjack(const Blackjack &other);
   Blackjack & operator=(const Blackjack &rhs);
   ~Blackjack();

   static const int MAX_CARDS = 5;
   static const int MIN_PLAYERS = 2;
   static const int MAX_PLAYERS = 10;
   static const int MAX_WIN = 21;
   static const int DFLT_NUM_CARDS = 2;

   void game();

private:
   PokerHand *players;
   int numPlayers;
   PokerDeck masterDeck;

private:
   void init(int numPlayers = MIN_PLAYERS);
   bool hit(int playerNumber);
   int sum(int playerNumber) const;
   void showHand(int playerNumber) const;
   void outputWinner() const;

public:
   class InvalidPlayerIndexException{};
};

#endif /* defined(__Card_Games__Blackjack__) */
