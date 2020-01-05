//
//  Card.h
//  Card Games
//

#ifndef __Card_Games__Card__
#define __Card_Games__Card__

#include <iostream>

template <typename ValType = int>
class Card
{
protected:
   ValType val1;

public:
   virtual bool setVal1(ValType newVal) = 0;
   virtual ValType getVal1() const = 0;
   virtual std::string toString() const = 0;
};

#endif /* defined(__Card_Games__Card__) */
