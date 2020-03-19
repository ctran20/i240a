CXX = g++
CXXFLAGS = -g -Wall -std=c++17
TARGETS = nums
OFILES = nums.o

all: 		$(TARGETS)

nums:		$(OFILES)
		$(CXX) $(OFILES) -o $@

.phony:		clean

clean:
		rm -f *~ *.o $(TARGETS)

nums.o: nums.cc
