/*
  Problem:
  String Compression - implement a method to perform basic string compression
  using the counts of repeated characters. For example, the string aabcccccaaa
  would become a2b1c5a3. If the compressed string would ot become smaller than
  the original string, then the method should return the original string. You
  can assume the string only has uppercase and lowercase letters (a-z).

  BCR = o(n) - have to scan string at least once.

  Sol 1, brute force, O(n^2)#
  Sol 2, use std::vector<> (as ArrayList) to avoid string copy

  Time - 31 mins (problem to code)
  Good - no syntax error, paper compiled with example and found two bugs
  Mistakes:
  a) logical mistake (for loop at 29, didnt paper compile it for end conditions) i.e. no boundary checking
  b) Try improving algorithm next time (BUD optimization)
  c) *** time complexity calculated incorrectly brute force algo is o(n^2) because
     string concatenation on line 37 is o(n^2). Improve algorithm now...
*/

#include <iostream>
#include <string>
#include <vector>

//This takes o(n^2) because of concatenation
std::string compress(const std::string& input)
{
  std::string output;
  unsigned int pin = 0;
  unsigned int outputCount = 0;

  for( unsigned int i = 0 ; i <  input.size() ; i++ ) {
    if(!i) continue;

    if( (i+1 == input.size()) || input[pin] != input[i] ) {
       output += input[pin];
       output += (i - pin) + '0';
       pin = i;
       outputCount += 2;
    }
  }
  if( outputCount > input.size() ) {
     return input;
  }
  return output;
}


std::string compress2(const std::string& input)
{
  std::vector<char> output(input.size()+1);
  unsigned int outputCount = 0;
  unsigned int pin = 0;

  for( unsigned int i = 0 ; i <  input.size() ; i++ ) {
    if(!i) continue;

    if( (i+1 == input.size()) || (input[pin] != input[i]) ) {
       output.push_back(input[pin]);
       output.push_back((i - pin) + '0');
       pin = i;
       outputCount += 2;
    }
    if( outputCount > input.size()) {
       return input;
    }
  }

  if( outputCount > input.size() ) {
     return input;
  }
  return std::string(output.begin(), output.end());
}



int main(int argc, char **argv)
{
  if( argc < 2 ) {
     std::cerr << "please input string" << std::endl;
     return 1;
  }
  std::cout << "Input =" << argv[1] << ", output =" << compress2(argv[1]) << std::endl;
  return 0;
}
