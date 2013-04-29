#include "C.hpp"
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "CSerialization.hpp"
#include "Serializer.hpp"
//BOOST_CLASS_EXPORT_KEY( A );
//BOOST_SERIALIZATION_ASSUME_ABSTRACT(A);

int main(int argc, char ** argv)
{

    Serializer s;
    s.save();
    
}

