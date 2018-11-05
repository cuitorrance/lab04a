tests: tests.cpp WordCount.cpp tddFuncs.cpp
	g++ -std=c++11 tests.cpp WordCount.cpp tddFuncs.cpp -o tests

runtests: tests
	./tests

clean:
	/bin/rm -f tests WordCount *.o
