#include "C.hpp"
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/shared_ptr.hpp>


int main(int argc, char ** argv)
{

	try {
	        //shared_ptr
		boost::shared_ptr<C> pc(new C);
		pc->c = 7;
		boost::shared_ptr<A> a(pc);
		//obj
		C c;
		c.c = 8;
		//ref
		C c2;
		c2.c = 9;
		A& ra = c2;
		
		std::ofstream ofs("C.ba");
		::boost::archive::binary_oarchive oa(ofs);
                oa << a;
	        oa << c;
	        oa << ra;
	        std::cout<<"Value stored ptr: "<<a->get()<<std::endl;
	        std::cout<<"Value stored obj: "<<c.get()<<std::endl;
	        std::cout<<"Value stored ref: "<<ra.get()<<std::endl;
	}
	catch(const std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;

	}
	
	try {
	        std::ifstream ifs("C.ba");
		::boost::archive::binary_iarchive ia(ifs);
		boost::shared_ptr<A> pc;
		ia & pc;
		
		C c;
		ia & c;
		
		C c2;
		A& ra = c2;
		ia & ra;
		
		std::cout<<"Finished deserialize"<<std::endl;
	        std::cout<<"pointer adr: "<<pc.get()<<std::endl;
	        
	        std::cout<<"Value loaded ptr: "<<pc->get()<<std::endl;
	        std::cout<<"Value loaded obj: "<<c.get()<<std::endl;
	        std::cout<<"Value loaded ref: "<<ra.get()<<std::endl;
	        
	}
	catch(const std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;

	}

}

