#include <iostream>
#include "WordCount.h"
#include "tddFuncs.h"
#include <vector>
#include <fstream>

using namespace std;

int main()
{
  cout << "Running Tests:" << endl;

  //add list of words to vector 
  vector<string> v;
  string word;

  ifstream infile("words.dat");
  while (infile >> word)
    {
      v.push_back(word);
    }

  //testcode:
  /* for ( unsigned n = 0; n <v.size(); n++)
    {
      cout << v.at(n) << endl;
    }
  */

  WordCount w;
  int i = 0;
  
  for (unsigned n = 0; n < v.size(); n++)
    {
      cout << "-----------------" << endl;
      cout << v.at(n) << endl ;
      i = w.incrWordCount( v.at(n) );
      i = w.incrWordCount( v.at(n) );
      cout << "total unique words: " << w.getNumUniqueWords() << endl;
      cout << "total words: " << w.getTotalWords() << endl;
    }

       
  return 0;
}
