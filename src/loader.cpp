#include "A.hpp"
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/shared_ptr.hpp>
//#include "C.hpp"
#include "CSerialization.hpp"
#include "Serializer.hpp"

int main(int argc, char ** argv)
{
    doLink();
    Serializer s;
    s.load();
}

