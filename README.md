##Boost python testing
-----

Simple test for boost python.

Build
----

From a build dir:

$ cmake ..  
$ make  


Run
----

From a python interpreter (within the build dir):

In [1]: import libpyexamples  

In [2]: w = libpyexamples.World ()  

In [3]: w.greet ()  
Out[3]: 'Hello, World!'  

In [4]: w.set ('new message')  

In [5]: w.greet ()  
Out[5]: 'new message'  

