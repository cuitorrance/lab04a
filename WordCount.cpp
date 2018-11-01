// WordCount.cpp
// Written by Richert Wang for CS 32, F18.

#include "WordCount.h"
#include <stdio.h>
#include <ctype.h>

using namespace std;

// Default constructor
WordCount::WordCount() {
}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
  size_t counter = 0;
  for (int i = 0; i < CAPACITY; i++)
    {
      for (int j = 0; j < table[i].size(); j++)
	{
	  counter += (table[i].at(j)).second;
	}
    }
  return counter;
}

int WordCount::getNumUniqueWords() const {
  size_t counter = 0;
  for (int i = 0; i < CAPACITY; i++)
    {
      for (int j = 0; j < table[i].size(); j++)
	{
	  counter += 1;
	}
    }
  return counter;
}

int WordCount::getWordCount(std::string word) const {
  size_t i = hash(word);
  for ( int j = 0; j < table[i].size();j++)
    {
      if ( ((table[i].at(j)).first).compare(word) == 0)
         {
	   return (table[i].at(j)).second;
	 }
    }
}
	

int WordCount::incrWordCount(std::string word) {
  return -1;
}


bool WordCount::isWordChar(char c) {
	// STUB
	return false;
}


std::string WordCount::stripWord(std::string word) {
  string ans = "";
  
  for ( int i = 0; i < word.length(); i++)
    {
      if ( isalpha(word[i]) || word[i] == '-' || word[i] == '\'')
	{
	  ans += word[i];
	}
    }
  return ans;
}
