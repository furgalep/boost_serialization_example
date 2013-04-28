#ifndef CSS_SS_HPP
#define CSS_SS_HPP

#include <boost/serialization/export.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include "C.hpp"

void exportC()
{
    boost::serialization::void_cast_register<C, A>((C*)NULL, (A*)NULL);
}


BOOST_CLASS_EXPORT_KEY( C );

#endif
