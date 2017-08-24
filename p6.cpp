/*
 Problem:
 One away - You can perform three edits on it namely, insert , remove or replace. 
 Given two strings find that they are one (or zero) edits away.
 E.g pale, ple = true ; pale, pales = true; pale, bale = true; pale, bake = false

 BCR = 2 * O(n) have to scan both strings at least once

 sol #1
 Brute Force = compare boths strings for insert, remove and replace separately.
 insert by checking for only allowed additional char; remove by only one less
 char and rest chars to be similar; replace by only one different char size to be same.

 In all cases only 1 'change' is allowed. 

 sol #2 (2 * O(n)
 Create associative array of first string and then start scanning other string and
 reduce count in first array if similar char found. At the end of the scan, associative
 array will have 'one -1' if insert operation performed or '+1' for remove operation
 '+2' for replace operation (size of strings must be same).

 Problem to code = 30 mins
 Logical mistakes:
 # arrayIndex calculation didnt round off index from 0 but directly char c
 
*/

#include <iostream>
#include <string>
const int totalChars = 32;

int arrayIndex(char c)
{
  if( (c >= 'a') && (c <= 'z') ) {
    return c - 'a';
  } else if ( c >= 'A' && c <= 'Z' ) {
    return  c - 'A';
  }
  return -1;
}

int main(int argc, char **argv)
{
  std::string orig = argv[1];
  std::string edit = argv[2];

  int origSize = 0;

  int charMap[totalChars] = {0};
  for( char c : orig ) {
    int i = arrayIndex(c);
    if(i < 0 ) {
      return 1;
    }
    charMap[i]++;
    origSize++;
  }


  int editSize = 0;
  for( char c : edit ) {
    int i = arrayIndex(c);
    if(i < 0 ) {
      return 1;
    }
    editSize++;
    if( charMap[i] ) {
      charMap[i]--;
    } else {
      charMap[i]++;
    }
  }

  if( (origSize-editSize < -1) || (origSize-editSize > 1) ) {
    std::cout << "Not one away" << std::endl;
    return 1;
  } 

  int totalCount = 0;
  for( int i = 0; i < totalChars ; i++ ) {
    totalCount += charMap[i];
  }

  if( totalCount <= 2 ) {
     std::cout << "One away!" << std::endl;
  } else {
     std::cout << "Not One Away" << std::endl;
  }

  return 0;
}
