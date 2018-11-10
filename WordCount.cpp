// WordCount.cpp
// Written by Richert Wang for CS 32, F18.

#include "WordCount.h"
#include <stdio.h>
#include <ctype.h>
#include <cctype>

//testpurposes
#include <iostream>
#include <fstream>

// Default constructor
WordCount::WordCount() {
  for ( unsigned i =0; i < CAPACITY; i++)
    {
      table[i].clear();
    }
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
  int counter = 0;
  for (unsigned i = 0; i < CAPACITY; i++)
    {
      for (unsigned j = 0; j < table[i].size(); j++)
	{
	  counter += static_cast<int>( (table[i].at(j)).second );
	}
    }
  return counter;
}

int WordCount::getNumUniqueWords() const {
  int counter = 0;
  for (unsigned i = 0; i < CAPACITY; i++)
    {
      for (unsigned j = 0; j < table[i].size(); j++)
	{
	  counter++;
	}
    }
  return counter;
}
std::string WordCount::toUp(std::string word){
  std::string ans = "";
  for (unsigned i = 0; i < word.length();i++)
    {
      ans += toupper(word[i]);
    }
  return ans;
}
int WordCount::getWordCount(std::string word) const {
  std::string fword = stripWord(word);
  if (fword.compare("") == 0) return 0;
  size_t i = hash(fword);
  for ( unsigned j = 0; j < table[i].size();j++)
    {
      if ( ((table[i].at(j)).first).compare(fword) == 0)
         {
	   return static_cast<int>( (table[i].at(j)).second );
	 }
    }
  return 0;
}
	

int WordCount::incrWordCount(std::string word) {
  std::string fword = stripWord(word);
  if (fword.compare("") == 0) return 0;
  size_t i = hash(fword);
  int index = 0;
  if ( getWordCount(fword) == 0)
    {
      std::pair<std::string,size_t> nword;
      nword.first = fword;
      nword.second = 1;
      table[i].push_back(nword);
      //std::cout << nword.first << std::endl;
      return 1;
    }
  else
    {
      for (unsigned j = 0; j <table[i].size();j++)
	{
	  if ( ((table[i].at(j)).first).compare(fword) == 0)
	    {
	      index = j;
	    }
	}
      (table[i].at(index)).second++;
      //std::cout << (table[i].at(index)).first << std::endl;
      return (table[i].at(index)).second;
    }     
}


bool WordCount::isWordChar(char c) {
  if (isalpha(c))
    {
      return true;
    }
  else
    {
      return false;
    }
}


std::string WordCount::stripWord(std::string word) {
  std::string ans = "";
  
  for ( unsigned i = 0; i < word.length(); i++)
    {
      if ( isalpha(word[i]) )
	{
	  ans += word[i];
	}
      else if ( word[i] == '-' || word[i] == '\'')
	{
	  if ( i -1 < 1)
	    {
	      //do nothing
	    }
	  else
	    {
	      ans += word[i];
	    }
	}
    }
  return ans;
}
