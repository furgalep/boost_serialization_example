#include "A.hpp"
#include <boost/serialization/export.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>



A::A(){}
A::~A(){}

BOOST_CLASS_EXPORT_IMPLEMENT( A );


template<class Archive>
void A::load(Archive & ar, const unsigned int version){}
    
template<class Archive>
void A::save(Archive & ar, const unsigned int version) const{}

template void A::save(boost::archive::binary_oarchive & ar, const unsigned int version) const;
template void A::load(boost::archive::binary_iarchive & ar, const unsigned int version);
template void A::save(boost::archive::text_oarchive & ar, const unsigned int version) const;
template void A::load(boost::archive::text_iarchive & ar, const unsigned int version);
template void A::save(boost::archive::xml_oarchive & ar, const unsigned int version) const;
template void A::load(boost::archive::xml_iarchive & ar, const unsigned int version);
