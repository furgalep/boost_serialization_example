#ifndef _A_H_
#define _A_H_

#include <boost/serialization/split_member.hpp>
#include <boost/serialization/shared_ptr.hpp> 


class A
{
public:
    A();
    virtual ~A();

    virtual int get() const = 0;

    BOOST_SERIALIZATION_SPLIT_MEMBER()
    
    template<class Archive>
    void load(Archive & ar, const unsigned int version){}
    
    template<class Archive>
    void save(Archive & ar, const unsigned int version) const{}
    
};

BOOST_SERIALIZATION_SHARED_PTR(A)

#endif /* _A_H_ */
