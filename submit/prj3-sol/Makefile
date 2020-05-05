CXX = g++
CXXFLAGS = -g -Wall -std=c++17

all: 		multi-queues

multi-queues:	multi-queues.o command.o job.o command-stream.o
		$(CXX) multi-queues.o command.o job.o command-stream.o -o $@

.phony:		clean

clean:
		rm -f *~ *.o multi-queues

multi-queues.o: multi-queues.cc heaps.hh
command.o: command.cc command.hh
command-stream.o: command-stream.cc command-stream.hh
job.o: job.cc