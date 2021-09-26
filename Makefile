output: command-stream.cc command.cc heap.hh command-stream.hh Comp0.hh Comp1.hh command-test.cc job.cc
		g++ -w Comp0.hh Comp1.hh command-stream.cc heap.hh command.cc command-test.cc job.cc -o multi-queues

clean:
		rm *.o multi-queues
