#ifndef _C_H_
#define _C_H_

#include "A.hpp"
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/nvp.hpp>

class C : public A
{
public:
    C();
    virtual ~C();

    int c;

    virtual int get(){ return c;}
    BOOST_SERIALIZATION_SPLIT_MEMBER()


    template<class Archive>
    void load(Archive & ar, const unsigned int version)
        {
            //boost::serialization::void_cast_register<C, A>((C*)NULL, (A*)NULL);
            ar >> BOOST_SERIALIZATION_BASE_OBJECT_NVP(A);
            ar >> BOOST_SERIALIZATION_NVP(c);
        }

    template<class Archive>
    void save(Archive & ar, const unsigned int version) const
        {
            //boost::serialization::void_cast_register<C, A>((C*)NULL, (A*)NULL);
            ar << BOOST_SERIALIZATION_BASE_OBJECT_NVP(A);
            ar << BOOST_SERIALIZATION_NVP(c);
        }

    
    
};


#endif /* _C_H_ */
