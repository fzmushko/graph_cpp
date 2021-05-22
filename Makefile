all: tests
tests: tests.o graph.o
	g++ graph.o tests.o -o tests -fprofile-arcs -ftest-coverage
tests.o: tests.cpp
	g++ -c tests.cpp -fprofile-arcs -ftest-coverage
graph.o: graph.cpp
	g++ -c graph.cpp -fprofile-arcs -ftest-coverage

clean: 
	rm -rf *.o *.gcno *.gcda *.gcov tests