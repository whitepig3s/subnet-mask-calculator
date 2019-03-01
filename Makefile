# Makefile of Bernoulli Trial simulation
all:main.cpp
	g++ -c main.cpp "1-cidr list.cpp" 2-summarization.cpp 3-range.cpp 4-host.cpp
	g++ -o subnet-mask-calculator main.o "1-cidr list.o" 2-summarization.o 3-range.o 4-host.o
clean:
	rm -f *.o