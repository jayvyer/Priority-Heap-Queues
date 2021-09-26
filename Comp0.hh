#include "job.hh"
#include <iostream>

class Comp0
{
	public:
			static bool prior(Job a, Job b){
						return a.priority0 > b.priority0;
							}
};
