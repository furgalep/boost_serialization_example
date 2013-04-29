#include "CSerialization.hpp"

#include <boost/serialization/export.hpp>
// Because Frames only store DescriptorBase pointers, this code is necessary
// to register serializaiton of these types.
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>


BOOST_CLASS_EXPORT_IMPLEMENT( C );

template void C::save(boost::archive::binary_oarchive & ar, const unsigned int version) const;
template void C::load(boost::archive::binary_iarchive & ar, const unsigned int version);

int doLink()
{
    static int i = 0;
    return i;
}

