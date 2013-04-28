#include "A.hpp"
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/shared_ptr.hpp>
//#include "C.hpp"
#include "CSerialization.hpp"

int main(int argc, char ** argv)
{

	try {
        boost::shared_ptr<A> a1;
		
        {
            std::cout << "1\n";
            std::ifstream ifs("C.ba");
            ::boost::archive::binary_iarchive ia(ifs);
            ia >> a1;
        }

        std::cout << "a1: " << (void*) a1.get() << std::endl;

        //C * c1 = dynamic_cast<C*>(a1.get());
        //std::cout << "c1: " << (void*) c1 << std::endl;

        std::cout << "loaded: " << a1->get() << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;

	}

}

