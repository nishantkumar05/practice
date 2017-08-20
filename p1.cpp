//Start - 1:00 PM  - 2:00 PM

// Problem:
// Given smaller string s and a bigger string b, design an algorithm to find all
// permutations of the shorter string within the longer one. Print the location
// of each permutation.

// Example:
// s=les , b=isleselsdsleaabcels
// print      .  .    .      .  <--- i.e. 2,5,10,17


// BCR = o(n)
// BF algo ( O(n^2) ):
// In b, start with first char and check if that char exist in s then check
// next char with same operation and keep repeating untill you reach string
// size of s or char not found in s

// Better algo ( 2 * O(n) ):
// Store all chars in s in hash table. Start with 1st char in b and keep
// going until either char is not found in hash table or size of s has
// been iterated over.
// Create hash table of s = O(S) and enumerate and search chars of b O(B)
// Where S and B are num of chars in s and b respectively

#include <iostream>
#include <string>
#include <cstdint>
#include <unordered_map>
#include <functional>

using searchFunction = std::function<bool(char)>;

bool isInStdStr(char c, std::string str)
{
  for(uint32_t i = 0; i  < str.size() ; i++ )
  {
      if( c == str[i] ) {
          return true;
      }
  } 
  return false;
}

bool isInHashTable( char c, std::unordered_map<char, int> hashTable)
{
   return ( hashTable.find(c) != hashTable.end() );
}

void basicAlgo(std::string shortStr, std::string bigStr, searchFunction search)
{
  for( uint32_t i = 0, pin = 0; i < bigStr.size(); i++ ) {
      char currentChar = bigStr[i];
      if( !search(currentChar) ) {
          pin = 0;
          continue;
      } else if (  !pin) {
          pin = i+1;
      } else if ( ((i+1 - pin) + 1 ) == shortStr.size() ){
          std::cout <<  pin  << std::endl; 
          pin = 0;
      }
  }  
}


void bruteForceAlgo(std::string shortStr, std::string bigStr)
{
  std::cout << "Brute force algorithm ---" << std::endl;
  basicAlgo(shortStr, bigStr, std::bind(isInStdStr, std::placeholders::_1, shortStr)); 
}

void betterAlgo(std::string shortStr, std::string bigStr)
{
  std::unordered_map<char, int> hashTable;
  for( char c : shortStr ) {
      hashTable.insert(std::pair<char, int>(c, 0));
  }
  std::cout << "better algorithm ---" << std::endl;
  basicAlgo(shortStr, bigStr, std::bind(isInHashTable, std::placeholders::_1, hashTable)); 
}


int main(int argc, char **argv)
{
  std::string shortStr = "les";
  std::string bigStr   = "isleselsdsleaabcels";
  bruteForceAlgo(shortStr, bigStr);
  betterAlgo(shortStr, bigStr);
  return 0;
}
