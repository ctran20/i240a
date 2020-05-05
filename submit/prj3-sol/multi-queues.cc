#include <memory>
#include <string>
#include <istream>

#include <cstdlib>

#include "heaps.hh"
#include "command.hh"
#include "command-stream.hh"

void PrintJob(Job job, std::string cmd) {
	std::cout << cmd
		<< " " << job.id
		<< " " << job.priority0
		<< " " << job.priority1 << std::endl;
}

int
main(int argc, char* argv[])
{
  if (argc != 2) {
    std::cerr << "usage: " << argv[0] << " FILE_PATH" << std::endl;
    std::exit(1);
  }
  
  CommandStream commandIn(argv[1]); //create command stream

  QueueZeroHeap queueZero;
  QueueOneHeap queueOne;

  for (std::unique_ptr<Command> commandP = commandIn.next();
       commandP != nullptr;
       commandP = commandIn.next()) {
	if (commandP->cmd == Command::Cmd::ENTER) {
		EnterCommand* enterP = dynamic_cast<EnterCommand*>(commandP.get());
		PrintJob(enterP->job, "enter");
		queueZero.enqueue(enterP->job);
	}
	else if (commandP->cmd == Command::Cmd::MOVE) {
		if (queueZero.size() > 0) {
			Job job = queueZero.dequeue();
			PrintJob(job, "move");
			queueOne.enqueue(job);
		}
	}
	else {
		if (queueOne.size() > 0) {
			PrintJob(queueOne.dequeue(), "leave");
		}
	}
  }
}
