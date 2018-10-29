// WordCount.cpp
// Written by Richert Wang for CS 32, F18.

#include "WordCount.h"

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
	// STUB.
	return -1;
}

int WordCount::getNumUniqueWords() const {
	// STUB
	return -1;
}

int WordCount::getWordCount(std::string word) const {
	// STUB
	return -1;
}
	

int WordCount::incrWordCount(std::string word) {
	// STUB
	return -1;
}


bool WordCount::isWordChar(char c) {
	// STUB
	return false;
}


std::string WordCount::stripWord(std::string word) {
	// STUB
	return "";
}
