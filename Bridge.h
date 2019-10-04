//
//  Bridge.h
//  Card Games
//
//  Created by Mitchell Tanbun on 27/12/18.
//  Copyright (c) 2018 Mitchell Tanbun. All rights reserved.
//

#ifndef __Card_Games__Bridge__
#define __Card_Games__Bridge__

#include <iostream>
#include "PokerDeck.h"
#include "PokerHand.h"

class Bridge
{
private:
   PokerHand *players;
   static const int NUM_PLAYERS = 4;
   
public:
   void game();

private:
   int winnerOfSet() const;
};

bool operator<(const PokerCard& lhs, const PokerCard& rhs);

#endif /* defined(__Card_Games__Bridge__) */
