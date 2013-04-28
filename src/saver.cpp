#include "C.hpp"
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "CSerialization.hpp"

//BOOST_CLASS_EXPORT_KEY( A );
//BOOST_SERIALIZATION_ASSUME_ABSTRACT(A);

int main(int argc, char ** argv)
{
    
	try {
        //boost::serialization::void_cast_register<C, A>((C*)NULL, (A*)NULL);
        //boost::archive::detail::extra_detail::guid_initializer<C> init;
        //init.export_guid();
        exportC();
		boost::shared_ptr<C> c1(new C);
		c1->c = rand();
		boost::shared_ptr<A> a1(c1);

		boost::shared_ptr<C> c2(new C);
		c2->c = rand();
		boost::shared_ptr<A> a2(c2);
		
        {
            std::cout << "1\n";
            std::ofstream ofs("C.ba");
            ::boost::archive::binary_oarchive oa(ofs);
            //oa << c1;
            oa << a1;
            std::cout << "saved " << c1->get() << std::endl;
        }


        {
            std::cout << "2\n";
            std::ofstream ofs("A.ba");
            ::boost::archive::binary_oarchive oa(ofs);
            oa << a2;
        }

	}
	catch(const std::exception & e)
	{
		std::cout << "Exception: " << e.what() << std::endl;

	}

}

