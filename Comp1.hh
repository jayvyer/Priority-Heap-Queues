#include "job.hh"

class Comp1
{
	public:
			static bool prior(Job a, Job b){
						return a.priority1 < b.priority1;
							}
};
