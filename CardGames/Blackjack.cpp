//
//  Blackjack.cpp
//  Card Games
//

#include "Blackjack.h"

Blackjack::Blackjack(int numPlayers)
{
   if (numPlayers < MIN_PLAYERS)
      this->numPlayers = MIN_PLAYERS;

   else if (numPlayers > MAX_PLAYERS)
      this->numPlayers = MAX_PLAYERS;

   else
      this->numPlayers = numPlayers;

   init(this->numPlayers);
}

void Blackjack::init(int numPlayers)
{
   if (numPlayers < MIN_PLAYERS || numPlayers > MAX_PLAYERS)
      return;
   players = new PokerHand[numPlayers];
   masterDeck = PokerDeck(1);
   for (int i = 0; i < numPlayers * DFLT_NUM_CARDS; i++)
      hit(i % numPlayers);
}

Blackjack::Blackjack(const Blackjack &other)
{
   *this = other;
}

Blackjack & Blackjack::operator=(const Blackjack &rhs)
{
   numPlayers = rhs.numPlayers;
   if (players != nullptr)
      return *this;
   
   for (int i = 0; i < numPlayers; i++)
      players[i] = rhs.players[i];
   return *this;
}

Blackjack::~Blackjack()
{
   delete [] players;
}

void Blackjack::game()
{
   if (players == nullptr)
   {
      std::cout << "Error: Game ended" << endl;
      return;
   }
   std::string *userInput;
   const std::string showCmd = "show", hitCmd = "hit", standCmd = "stand";
   std::cout << "Commands: \n\"" << showCmd << "\" to show current hand"
             << std::endl << "\"" << hitCmd << "\" to hit" << std::endl
             << "\"" << standCmd << "\" to stand" << std::endl;

   for (int i = 0; i < numPlayers; i++)
   {
      std::cout << "Player " << i + 1 << ": ";
      showHand(i);
      while (true)
      {
         userInput = new std::string;
         std::cout << std::endl << ":";
         std::getline(cin, *userInput);

         if (*userInput == showCmd)
            showHand(i);
         else if (*userInput == hitCmd)
         {
            if (hit(i))
               std::cout << players[i].back();
            else
               std::cout << "No longer able to hit" << endl;
         }
         else if (*userInput == standCmd)
         {
            std::cout << std::endl;
            break;
         }
         else
            std::cout << "Please type a valid command" << std::endl;

         delete userInput;
      }
   }
   outputWinner();
   delete [] players;
   players = nullptr;
}

int Blackjack::sum(int playerNumber) const
{
   if (playerNumber < 0 || playerNumber >= numPlayers)
      throw InvalidPlayerIndexException();
   
   int sum = 0, numAces = 0, currFace;
   
   for (int i = 0; i < players[playerNumber].getNumCards(); i++)
      if (players[playerNumber][i].getFace() == 1)
         numAces++;

   for (int i = 0; i < players[playerNumber].getNumCards(); i++)
   {
      currFace = players[playerNumber][i].getFace();
      if (currFace == 0)
         throw PokerCard::InvalidIndexException();
      else if (currFace == 1)
         sum += 11;

      else if (currFace < 10)
         sum += currFace;

      else
         sum += 10;
   }

   while (numAces > 0 && sum > Blackjack::MAX_WIN)
   {
      sum -= 10;
      numAces--;
   }

   return sum;
}

bool Blackjack::hit(int playerNumber)
{
   if (playerNumber < 0 || playerNumber >= numPlayers ||
       players[playerNumber].getNumCards() >= MAX_CARDS || sum(playerNumber) > MAX_WIN)
      return false;

   masterDeck.give(players[playerNumber]);
   return true;
}

void Blackjack::showHand(int playerNumber) const
{
   if (playerNumber < 0 || playerNumber >= numPlayers)
      throw InvalidPlayerIndexException();
   std::cout << players[playerNumber];
}

void Blackjack::outputWinner() const
{
   if (players == nullptr)
      return;
   std::list<int> winnerIndices;
   int winningValue;

   for (int i = 0; i < numPlayers; i++)
   {
      if (winnerIndices.empty() && sum(i) <= MAX_WIN)
      {
         winningValue = sum(i);
         winnerIndices.push_back(i);
         continue;
      }

      if (sum(i) == winningValue)
         winnerIndices.push_back(i);

      else if (sum(i) > winningValue && sum(i) <= MAX_WIN)
      {
         winningValue = sum(i);
         winnerIndices.clear();
         winnerIndices.push_back(i);
      }
   }

   if (winnerIndices.empty())
      std::cout << "No one wins" << std::endl;

   else
   {
      std::cout << "Player(s) ";
      typename std::list<int>::const_iterator iter = winnerIndices.begin();
      std::cout << *iter + 1; // iter points to index, not to player number
      iter++;
      // append commas after subsequent winners
      for (iter; iter != winnerIndices.end(); iter++)
         std::cout << ", " << *iter + 1; 
      std::cout << " wins with " << winningValue << " points!" << std::endl;
   }
}



