//
//  UNOCard.h
//  Card Games
//

#ifndef __Card_Games__UNOCard__
#define __Card_Games__UNOCard__

#include <iostream>
#include "Card.h"

class UNOCard : public Card<char>
{
private:
   enum color{invalid, red, blue, yellow, green, wild};
   color currColor;
   
public:
   static const std::string POSSIBLE_CHAR;
};

#endif /* defined(__Card_Games__UNOCard__) */
