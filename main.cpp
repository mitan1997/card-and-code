//
//  main.cpp
//  Card Games
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <ctime>
#include "Blackjack.h"
#include "Hearts.h"

using namespace std;

template <class T = string>
T input()
{
   string userStr;
   T retVal;
   getline(cin, userStr);
   istringstream(userStr) >> retVal;
   return retVal;
}

int main(int argc, char *argv[])
{
   unsigned seed = (unsigned)(time(0L));
   cout << "Seed is: " << seed << endl << endl;
   srand(seed);

//   PokerDeck myDeck;
//   myDeck.shuffle();
//   while (!myDeck.empty())
//   {
//      cout << myDeck.top() << endl;
//      myDeck.pop();
//   }
   
//   PokerDeck emptyDeck(0);
//   emptyDeck.push(randCard());
//   cout << emptyDeck.top() << endl;
//
//   PokerHand myHand;
//   cout << myHand << endl;
//
//   for (int i = 0; i < 10; i++)
//      myHand.addCard(randCard());
//   cout << myHand;
////   myHand.sort<PokerHand::FaceAscending>();
//   cout << myHand;
//   cout << myHand.play(5) << endl;
//   cout << myHand;
//   myHand.sort<PokerHand::SuitAscending>();
//   cout << myHand;
//   return 0;

   std::string *userInput;
   userInput = new std::string;
   int numPlayers;
   std::cout << "Please enter number of players: ";
   numPlayers = input<int>();
   Blackjack game(numPlayers);
   game.game();
   return 0;

   
//   string userInput;
//   ofstream file_history;
//   file_history.open("/Users/mitchelltanbun/Documents/Xcode Workspace/"
//                     "Personal Projects/Card Games/Card Games/Games History.txt");
//   time_t now = time(0);
//   file_history << "Game on " << localtime(&now) << endl << endl;
//   const Deck deck1;
//
//   Blackjack game;
//   for (int i = 0; i < game.getNumCards(); i++)
//   {
//      file_history << game.getUserHand()[i].toString() << endl;
//      game.getUserHand()[i].display();
//   }
//   
//   do
//   {
//      if (game.sum() == game.MAX_WIN)
//         break;
//      cout << "Type \"Hit\" to hit, or \"Stand\" to stand: ";
//      getline(cin, userInput);
//      if (toupper(userInput[0]) == 'H')
//      {
//         game.hit();
//         file_history << game.getUserHand()[game.getNumCards() - 1].toString() << endl;
//         game.getUserHand()[game.getNumCards() - 1].display();
//      }
//   }
//   while (toupper(userInput[0]) != 'S' &&
//          game.getNumCards() < game.MAX_NUM_CARDS &&
//          game.sum() < game.MAX_WIN);
//   
//   if (game.getNumCards() == game.DEFAULT_NUM_CARDS &&
//       game.sum() == game.MAX_WIN)
//   {
//      cout << "BLACKJACK!!!";
//      file_history << "BLACKJACK!!!" << endl;
//      return 0;
//   }
//
//   cout << "Your points is " << game.sum();
//   file_history << "Your points is " << game.sum();
//
//   file_history.close();
//   return 0;

   // */

//   Hearts game;
//   for (int i = 0; i < 4; i++)
//      cout << game[i];
//   return 0;
}




