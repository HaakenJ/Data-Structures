cmake_minimum_required(VERSION 3.17)
project(p4)

set(CMAKE_CXX_STANDARD 14)

add_executable(p4 main.cpp Patient.cpp Patient.h PatientPriorityQueue.cpp PatientPriorityQueue.h)