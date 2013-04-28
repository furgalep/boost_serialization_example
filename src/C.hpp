#ifndef _C_H_
#define _C_H_

#include "A.hpp"
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/export.hpp>

class C : public A
{
public:
    C();
    virtual ~C();

    int c;

    virtual int get(){ return c;}
    BOOST_SERIALIZATION_SPLIT_MEMBER()

    template<class Archive>
    void load(Archive & ar, const unsigned int version);
    
    template<class Archive>
    void save(Archive & ar, const unsigned int version) const;

    
    
};
BOOST_CLASS_EXPORT_KEY( C );


#endif /* _C_H_ */
