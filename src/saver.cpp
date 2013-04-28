#include "C.hpp"
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/shared_ptr.hpp>
//#include "CSerialization.hpp"

//BOOST_CLASS_EXPORT_KEY( A );
//BOOST_SERIALIZATION_ASSUME_ABSTRACT(A);

int main(int argc, char ** argv)
{

	try {
		boost::shared_ptr<C> c(new C);
		c->c = 7;
		boost::shared_ptr<A> a(c);
		std::ofstream ofs("C.ba");
		::boost::archive::binary_oarchive oa(ofs);
		A* aa = a.get();
		oa << aa;
	        std::cout<<"Value stored: "<<aa->get()<<std::endl;
	}
	catch(const std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;

	}
	
	try {
	        std::ifstream ifs("C.ba");
		::boost::archive::binary_iarchive ia(ifs);
	        A* aa;
	        ia & aa;
	        std::cout<<"Value loaded: "<<aa->get()<<std::endl;
	}
	catch(const std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;

	}

}

