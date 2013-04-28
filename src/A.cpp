#include "A.hpp"
#include <boost/serialization/export.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>


    template<class Archive>
    void A::load(Archive & ar, const unsigned int version){

    }

    template<class Archive>
    void A::save(Archive & ar, const unsigned int version) const
    {
    }

A::A(){}
A::~A(){}

BOOST_CLASS_EXPORT_IMPLEMENT( A );

template void A::save(boost::archive::binary_oarchive & ar, const unsigned int version) const;
template void A::load(boost::archive::binary_iarchive & ar, const unsigned int version);
