#include "Serializer.hpp"

#include "CSerialization.hpp"
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/shared_ptr.hpp>

Serializer::Serializer(){
    doLink();
}
Serializer::~Serializer(){}


void Serializer::save()
{
    try {
        //boost::serialization::void_cast_register<C, A>((C*)NULL, (A*)NULL);
        //boost::archive::detail::extra_detail::guid_initializer<C> init;
        //init.export_guid();
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

void Serializer::load()
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
