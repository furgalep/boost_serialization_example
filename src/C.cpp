#include "C.hpp"
#include <boost/serialization/export.hpp>
// Because Frames only store DescriptorBase pointers, this code is necessary
// to register serializaiton of these types.
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

    // template<class Archive>
    // void C::load(Archive & ar, const unsigned int version)
    //     {
    //         ar >> BOOST_SERIALIZATION_BASE_OBJECT_NVP(A);
    //         ar >> BOOST_SERIALIZATION_NVP(c);
    //     }

    // template<class Archive>
    // void C::save(Archive & ar, const unsigned int version) const
    //     {
    //         ar << BOOST_SERIALIZATION_BASE_OBJECT_NVP(A);
    //         ar << BOOST_SERIALIZATION_NVP(c);
    //     }



BOOST_CLASS_EXPORT_IMPLEMENT( C );
// template void C::save(boost::archive::binary_oarchive & ar, const unsigned int version) const;
// template void C::load(boost::archive::binary_iarchive & ar, const unsigned int version);

C::C() : c(0) {}
C::~C(){}



