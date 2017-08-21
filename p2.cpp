// Problem:
// Implement an algorithm to determine if a string has all unique characters.
// what if you cannot use additional data structures?
// E.g.:   "Algorithm" return true while "Common" returns false

// BCR = O(n)..you need to visit all the chars at least once

// BF solution ( O(n^2) = 1 + 2 + 3 ... + n = n ( n + 1 ) / 2 ):
// Start with dropping pin on 1st char & move along the array and break if 
// same char found. Move ping to next char do the same operation

// Better solution ( O(n) ) :
// Create 128 bit associative array of bools and drop the pin on 1st char
// and check if value on bool array corresponding to the dropped pin is 
// set to the true then return true


#include <iostream>
#include <string>
#include <vector>

bool isUnique(std::string str)
{
  bool bitmap[26] = {false};
  unsigned int i = 0;
  
  for( auto c : str ) {
    //Convert if problem assumes 'A' == 'a'
    if( c < 'a' ) {
      unsigned int distance = c - 'A';
      i = 'a' + distance;
    } else  {
      i = c - 'a';
    }

    if( bitmap[i] ) {
      return false;
    } else  {
      bitmap[i] = true;
    }
  }
  return true;
}

int main(int argc, char **argv)
{
  std::cout << "isUnique(\"Algoritham\") = " << isUnique("Algoritham") << std::endl;
  return 0;
}
