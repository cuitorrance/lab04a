main: tests WordCount

WordCount: WordCount.o
	g++ $^ -o  $@

tests: tests.o
	g++ $^ -o $@

clean:
	/bin/rm -f tests WordCount *.o
