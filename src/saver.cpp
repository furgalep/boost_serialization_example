#include "C.hpp"
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/shared_ptr.hpp>


int main(int argc, char ** argv)
{

	try {
		boost::shared_ptr<C> c(new C);
		c->c = 7;
		boost::shared_ptr<A> a(c);
		std::ofstream ofs("C.ba");
		::boost::archive::binary_oarchive oa(ofs);
                oa.register_type(static_cast<C *>(NULL));
                oa << a;
	        std::cout<<"Value stored: "<<a->get()<<std::endl;
	}
	catch(const std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;

	}
	
	try {
	        std::ifstream ifs("C.ba");
		::boost::archive::binary_iarchive ia(ifs);
                ia.register_type(static_cast<C *>(NULL));
		boost::shared_ptr<A> c;
		ia & c;
		std::cout<<"Finished deserialize"<<std::endl;
	        std::cout<<"pointer adr: "<<c.get()<<std::endl;
	        std::cout<<"Value loaded: "<<c->get()<<std::endl;
	        /*A* aa;
	        ia & aa;
	        std::cout<<"Value loaded: "<<aa->get()<<std::endl;*/
	        
	}
	catch(const std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;

	}

}

