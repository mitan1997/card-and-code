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

}

int Bridge::winnerOfSet() const {

}

bool operator<(const PokerCard& lhs, const PokerCard& rhs) {

}