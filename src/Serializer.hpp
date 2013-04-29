#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_

class Serializer
{
public:
    Serializer();
    virtual ~Serializer();

    void save();
    void load();
};


#endif /* _SERIALIZER_H_ */
