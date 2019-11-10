
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main
    main.cpp
    visitor.cpp
    iterator.cpp
    composite.cpp
)

ADD_EXECUTABLE(test
    test.cpp
    composite.cpp
    iterator.cpp
    visitor.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)