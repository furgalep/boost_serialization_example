#ifndef _C_H_
#define _C_H_

#include "A.hpp"
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/shared_ptr.hpp> 

class C : public A
{
public:
    C();
    virtual ~C();

    int c;

    virtual int get() const { return c;}
    BOOST_SERIALIZATION_SPLIT_MEMBER()

    template<class Archive>
    void load(Archive & ar, const unsigned int version){
        ar >> BOOST_SERIALIZATION_BASE_OBJECT_NVP(A);
        ar >> BOOST_SERIALIZATION_NVP(c);
    }
    
    template<class Archive>
    void save(Archive & ar, const unsigned int version) const{
            ar << BOOST_SERIALIZATION_BASE_OBJECT_NVP(A);
            ar << BOOST_SERIALIZATION_NVP(c);
    }

    
    
};
//BOOST_CLASS_EXPORT_KEY( C );
BOOST_SERIALIZATION_SHARED_PTR(C)


#endif /* _C_H_ */
