//
//  Bridge.cpp
//  Card Games
//

#include "Bridge.h"

Bridge::Bridge() {
   players = new PokerHand[NUM_PLAYERS];
}

Bridge::~Bridge() {
   delete [] players;
   players = nullptr;
}

void Bridge::game() {
   // TODO
}

int Bridge::winnerOfSet() const {
   return -1;
   // TODO
}

bool operator<(const PokerCard& lhs, const PokerCard& rhs) {
   return false;
   // TODO
}