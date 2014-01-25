#include <iostream>
#include <vector>

#include <Python.h>
#include <numpy/ndarraytypes.h>
#include <numpy/ndarrayobject.h>

#include <boost/python.hpp>

using namespace std;

const char* greet ()
{
    return "Hello, World!";
}

struct World
{
  World () : _msg ("Hello, World!") {}
  World (string msg) : _msg (msg) {}

  void set (string msg) {_msg = msg;}
  string greet () {return _msg;}

  string _msg;
};


class Data
{
public:
  Data () {import_array ();}
  ~Data () {}

  void set (PyObject *a)
  {
      PyArrayObject *arr = (PyArrayObject*) a;
      assert (arr->nd==_ndims);                      // should be 1d here
      assert (arr->descr->type_num==PyArray_DOUBLE); // should be double...

      _data.clear ();
      _data.resize (arr->dimensions[0]);

      for (int i=0;i<arr->dimensions[0];++i) {
          double *d = (double*) (arr->data + i*arr->strides[0]);
          _data[i] = *d;
      }
  }

  PyObject* squared ()
  {
      PyArrayObject *arr;

      int dims[1] = {static_cast<int> (_data.size ())};
      arr = (PyArrayObject*) PyArray_FromDims (_ndims, dims, PyArray_DOUBLE);

      double *sqd = new double[dims[0]];
      for (int i=0;i<dims[0];++i) sqd[i] = _data[i]*_data[i];
      arr->data = (char*) sqd;

      return PyArray_Return (arr);
  }

private:
  vector<double> _data;
  static const int _ndims = 1;
};


BOOST_PYTHON_MODULE (libpyexamples)
{
    using namespace boost::python;
    def ("greet", greet);

    class_<World>("World")
        .def (init<string> ())
        .def ("greet", &World::greet)
        .def ("set", &World::set)
    ;

    class_<Data>("Data")
        .def ("set", &Data::set)
        .def ("squared", &Data::squared)
    ;
}
