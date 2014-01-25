##Boost python testing
-----

Simple test for boost python. Tests the following functionality:

* call a function (greet ())
* create a basic object and set some primitive data (World ())
* create an object that can receive and return numpy arrays (Data ())

Build
----

From a build dir:

$ cmake ..  
$ make  


Run
----

From a python interpreter (within the build dir):

In [1]: import libpyexamples  

In [2]: libpyexamples.greet ()  
Out[2]: 'Hello, World!'  

In [3]: w0 = libpyexamples.World ()  

In [4]: w0.greet ()  
Out[4]: 'Hello, World!'  

In [5]: w0.set ('new hello message')  

In [6]: w0.greet ()  
Out[6]: 'new hello message'  

In [7]: w1 = libpyexamples.World ('hello init message')  

In [8]: w1.greet ()  
Out[8]: 'hello init message'  

In [9]: import numpy as np  

In [10]: a = np.arange (5, dtype='float')  

In [11]: d = libpyexamples.Data ()  

In [12]: d.set (a)  

In [13]: b = d.squared ()  
In [14]: b  
Out[14]: array([  0.,   1.,   4.,   9.,  16.])  

Notes
-----

The Data object is particularly brittle---there are no real checks right now.
The array based to it *must* be of double type and only a single dimension.

