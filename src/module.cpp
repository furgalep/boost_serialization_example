#include <boost/python.hpp>
#include "Serializer.hpp"

BOOST_PYTHON_MODULE(libboost_serialization_example_python)
{
    using namespace boost::python;

    class_<Serializer>("Serializer", init<>())
        .def("save", &Serializer::save)
        .def("load", &Serializer::load)
        ;

}
