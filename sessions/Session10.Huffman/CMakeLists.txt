cmake_minimum_required(VERSION 3.17)
project(Session10_Huffman)

set(CMAKE_CXX_STANDARD 14)

add_executable(Session10_Huffman huffman_test.cpp BitStream.cpp BitStream.h Huffman.cpp Huffman.h HuffNodeMinHeap.cpp HuffNodeMinHeap.h HuffNode.cpp HuffNode.h)