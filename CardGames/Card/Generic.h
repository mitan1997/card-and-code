#ifndef __Card_Games__Generic__
#define __Card_Games__Generic__

#include <vector>
#include <string>

/* Generic utility functions for parsing strings. */

std::vector<int> stringToIntVector(const std::string elems, char start = '[', char end = ']', 
                                   char delimiter = ',', bool ignoreWhitespace = true) {
   std::vector<int> result;
   int *buffer;
   for (int i = 0; i < elems.length(); i++) {
      if (ignoreWhitespace && elems[i] == ' ' || elems[i] == '\n') {

      }
   }

   return result;
}

std::vector<std::string> stringToStringVector(const std::string elems, char start = '[', char end = ']',
                                              char delimiter = ',', bool ignoreWhitespace = true) {
   std::vector<std::string> result;
   std::string* buffer;

   return result;
}

#endif /* defined(__Card_Games__Generic__ */