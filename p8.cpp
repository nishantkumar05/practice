/*
 Problem: Implement hash function
 50 mins!
 
 Good
  - No syntax issues in class (even with templates)

 Improvements required:
  - 

*/


#include <iostream>
#include <string>
#include <vector>


unsigned int hash(const std::string &str)
{
  unsigned int hash = 0;
  for(auto c : str) {
    hash += c;
  }
  return hash;
}

template<typename valT>
struct hashEntry {
  valT value;
  struct hashEntry<valT> *next;
  struct hashEntry<valT> *prev;
  hashEntry()
  {
    next = prev = nullptr;
  }
  ~hashEntry()
  {
    if( prev ) {
      prev->next = next;
    }
    if(next) {
      next->prev = prev;
    }
  }
};

const int totalHashEntries = 256;

using hashEntryIntStr = hashEntry<std::string>;
using hashEntryIntStrPtr = hashEntryIntStr *;

void printVals(hashEntryIntStrPtr (&hashEntries)[totalHashEntries])
{
  for(unsigned int i = 0; i < totalHashEntries; i++) {
    if(!hashEntries[i]) {
      continue;
    }
    hashEntryIntStrPtr tmp = hashEntries[i];
    std::cout << "hashEntries[" << i << "] => ";
    while(tmp) {
      std::cout << "("<< tmp->value << "),  "; 
      tmp = tmp->next;
    }
    std::cout << std::endl;
  } 
}

int main(int argc, char **argv)
{
  hashEntryIntStrPtr hashEntries[totalHashEntries] = {nullptr};
  for(int i = 1; i < argc; i++) {
    unsigned int hashValue = hash(argv[i]);
    unsigned int arrayValue = hashValue % totalHashEntries; //Simple array
    hashEntryIntStrPtr entry = new hashEntryIntStr;
    entry->value = argv[i];
    hashEntryIntStrPtr currentEntryInTable = hashEntries[arrayValue];
    if(!currentEntryInTable) {
      hashEntries[arrayValue] = entry;
    } else {
      while(currentEntryInTable->next) {
        currentEntryInTable = currentEntryInTable->next;
      }
      currentEntryInTable->next = entry;
      entry->prev = currentEntryInTable;
    }
  }

  printVals(hashEntries);
}
