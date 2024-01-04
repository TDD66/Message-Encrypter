cmake_minimum_required(VERSION 3.26)
project(Message_Encrypter)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Message_Encrypter
        Encryption.cpp
        LICENSE
        README.md
        RSA.h
        test/testRSA.cpp)
