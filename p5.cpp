/*
 Problem:
 Palindrome permutation: given a string with multiple words write a function
 to check if its a permutation of a palindrome. Palindrome is word or phrase
 that is same forwards or backwards. A permutation is rearrangement of letters.
 Plaindrome doesn't need to be limited to dictionary words. 

 Example: i/p = "tact coa", is it permutation of some palindrome?
    valid palindromes of that string exist e.g. = "taco cat", "atco cta"

 BCR = 2 * O(n) - one to create palindrome and other to check permutation

 Palindrome properties: even sized str has all chars occuring twice and odd sized str
 will have all chars twice except one

 Sol 1# Brute Force:
 Scan and create associate array of ints with its depecting number of times char
 appeared in string and array sbscript to be char itself. Scan this array once again
 and for odd size str only one char is allowed to have 1 occurence and all others
 must be even number of occurences 

 time = 33 mins to code.
 Logical mistakes: 
 #1 : charMap[c-'a'] array subscript was not chosen correctly
 #2 : oddOccurances was declared in for loop as well making outer oddOccurances
 to still contain 0 givin wrong result
*/
#include <iostream>
#include <string>

const int totalChars = 26;

bool isPalindrome(const std::string &str)
{
    //build charmap
    int charMap[totalChars] = {0};
    unsigned int charCount = 0;
    for( auto c : str ) {
        if( c != ' ') {
            charMap[c-'a']++;
            charCount++;
        }
    }

    int oddOccurances = 0;
    for( int i = 0 ; i < totalChars; i++ ) {
        if ( (charMap[i] % 2) == 1 ) {
            oddOccurances++;
        }
    }
    if ( charCount % 2 ) {
        return ( oddOccurances == 1 ) ? true : false; 
    } else {
        return ( oddOccurances == 0 ) ? true : false; 
    }
    return false;
}

int main(int argc, char **argv)
{
   std::string str = "tact coa";
   std::cout << std::boolalpha << "isPalindrome=" << isPalindrome(str) << std::endl;
}
