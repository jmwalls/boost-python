project (Python_example)
cmake_minimum_required (VERSION 2.8)

find_package (PythonLibs)
include_directories (${PYTHON_INCLUDE_DIRS})

find_package (Boost 1.45.0 COMPONENTS python)
include_directories (${Boost_INCLUDE_DIRS})

set (CMAKE_CXX_FLAGS "-u MAIN__ -Wall -Wundef -Wno-strict-aliasing --std=gnu++0x")

add_library (
    pyexamples SHARED
    pyexamples.cpp
    )
target_link_libraries (pyexamples
    boost_python
    ${PYTHON_LIBRARIES}
    ${Boost_LIBRARIES}
    )
