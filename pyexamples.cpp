#include <Python.h>
#include <boost/python.hpp>

const char* greet ()
{
    return "Hello, World!";
}

struct World
{
    World () : _msg ("Hello, World!") {}
    World (std::string msg) : _msg (msg) {}

    void set (std::string msg) {_msg = msg;}
    std::string greet () {return _msg;}

    std::string _msg;
};

BOOST_PYTHON_MODULE (libpyexamples)
{
    using namespace boost::python;
    def ("greet", greet);

    class_<World>("World")
        .def (init<std::string> ())
        .def ("greet", &World::greet)
        .def ("set", &World::set)
    ;
}
