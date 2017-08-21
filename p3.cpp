// Problem:
// Check if two strings are permutations of each other
// e.g. "nishantt" and  "inshantt" ( assuming all lower case, no spaces)

// BCR: 2 * O(n) - you have two visit both strings at least once

// Brute Force ( 2 * O(n^2) ):
// Fail if size is equal and then iterate over first string and check if that
// character is present in second string and do the same for other string

// Sol 1 (O(n log n) for binary sorting like logarithmic sort):
// Sort then iterate over both strings simultaneously and fail if different

// Sol 2 ( 2 * O(n) ):
// Create hash map of first string and then second string and fail if
// for some char in second string no collision found. This wont work without
// modification if chars within string are not unique 

// Sol 3 ( 3 * O(n) = twice for creating array for both string and once for comparing):
// Create associative array with char bieng the array index and value bieng
// number of times the char appears in the string.
// Compare associative array values and fail if they are not similar


// Mistakes: variable name mismatch, vector<syntax>, missing semicolon
//           vector include missing, logicall error on line 51 compared string instead of vector

// Completion time: design to code 30 mins


#include <iostream>
#include <string>
#include <vector>

const unsigned int totalChars = 128;

void prepareValues(std::vector<int> &vals, const std::string &str)
{
  for( auto c : str ) {
    vals[c]++;
  }
}


bool isPermutation(const std::string &a, const std::string &b)
{
  std::vector<int> aValues(totalChars,0);  
  std::vector<int> bValues(totalChars,0);  

  prepareValues(aValues, a); 
  prepareValues(bValues, b); 

  for(int i = 0 ; i < aValues.size() ; i++ ) {
    if( aValues[i] != bValues[i] ) {
      return false;
    }
  }
  return true;
}

int main(int argc, char **argv)
{
  std::string a = "nishantt";
  std::string b = "inshantt";

  std::cout << std::boolalpha << "Are \"" << a << "\" and \"" << b << "\" permutations? =" << isPermutation(a, b) << std::endl;
  return 0;
} 

