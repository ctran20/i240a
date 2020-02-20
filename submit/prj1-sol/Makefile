CXX = g++
CXXFLAGS = -g -Wall -std=c++17

OFILES = wordcounts.o

wordcounts:	$(OFILES)
		$(CXX) $(OFILES) -o $@

.phony:		clean
clean:
		rm -f *~ *.o wordcounts
