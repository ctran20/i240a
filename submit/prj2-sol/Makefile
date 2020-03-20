CXX = g++
CXXFLAGS = -g -Wall -std=c++17

all: 		seq-test nums

seq-test:	seq-test.o command.o
		$(CXX) seq-test.o command.o -o $@

nums:		nums.o
		$(CXX) nums.o -o $@

.phony:		clean

clean:
		rm -f *~ *.o seq-test nums

seq-test.o: seq-test.cc
command.o: command.cc command.hh
nums.o: nums.cc