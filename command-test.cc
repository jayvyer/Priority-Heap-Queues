#include <memory>
#include <string>
#include <istream>
#include <iostream>

#include <cstdlib>

#include "command.hh"
#include "command-stream.hh"
#include "heap.hh"



/** Test program for command stream */
int main(int argc, char* argv[] )
{
	  if (argc != 2) {
		      std::cerr << "usage: " << argv[0] << " FILE_PATH" << std::endl;
		          std::exit(1);
			    }

	    heap<Job, Comp0> max_heap;
	      heap<Job, Comp1> min_heap;

	        CommandStream commandIn(argv[1]); //create command stream
		  for (std::unique_ptr<Command> commandP = commandIn.next(); commandP != nullptr; commandP = commandIn.next()) {
			  	  if(commandP->cmd == 0){
					  		  EnterCommand* enterP = dynamic_cast<EnterCommand*>(commandP.get());
							  		  max_heap.insert(enterP->job);
									  		  std::cout << "enter " << enterP->job << std::endl;
											  	  }
				  	  if(commandP->cmd == 1){
						  		  auto temp = max_heap.removefirst();
								  		  min_heap.insert(temp);
										  		  std::cout << "move " << temp << std::endl;
												  	  }
					  	  if(commandP->cmd == 2){
							  		  if(min_heap.size() != 0){
										  			  std::cout << "leave " << min_heap.removefirst() << std::endl;
													  		  }
									  	  }
						  	}
}

