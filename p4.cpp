// Problem:
// URLify = given a string with sufficiently large memory already assigned
// to hold new string and its true size, replace all spaces in the string 
// with %20. The algorithm must perform operation in place.
// E.g. Input = "Mr  John     Smith     ", 23 
//     Output = "Mr%20John%20Smith"

// BCR = O(N) = have to scan string at least once

// Sol 1 ( 2 * O(n) ) -
// special conditions: starting spaces, in between 1 or more spaces, end spaces
// Start from end (drop pin at start) and continue untill we find first char 
// keep copying chars to the pin location and until the space is found, if space
// is found then insert %20 and continue ignoring other spaces after %20 is added 
// until some real char is found.
// Once all %20 are replaced, start from beginning and if %20 is encountered first
// without char is found then chop it off then copy all the chars at begenning and 
// add %0 at the end


// Output of program:
// Before ="Mr John Smith        "
// After  ="    Mr%20John%20Smith"

// No mistakes! except one logical mistake of using usigned int in for loop at line 36
//              Loop breaks on -1 (and 0 is invalid) and since i was unsigned int it 
//              never really reached -1  

// Time taken is long 1 hr

#include <iostream>
#include <string>

void URLify(std::string &url)
{
  if(url.empty()) return;

  bool copyingChars = false;
  for(int i = url.size()-1, pin = url.size()-1 ; i >= 0 ; i-- ) {
    if( (url[i] != ' ') ) {
      if(!copyingChars ) { //encountered first char
        copyingChars = true;
      }
      // encountered subsequent char
      url[pin] = url[i];
      url[i] = ' ';
      pin--;
    } else if ( url[i] == ' ' ) {
      if( copyingChars ) { // encountered space after chars
        pin = pin - 3;
        url[pin+1] = '%';
        url[pin+2] = '2';
        url[pin+3] = '0';
        copyingChars = false;
      }
    }
  }
}

int main(int argc, char **argv)
{
  std::string url = "Mr John Smith        ";
  std::cout << "Before =\"" << url << "\"" << std::endl; 
  URLify(url);
  std::cout << "After  =\"" << url << "\"" << std::endl; 
  return 0;
}
