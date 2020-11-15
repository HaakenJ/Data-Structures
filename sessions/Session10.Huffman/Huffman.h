//
// Created by Kevin Lundeen on 11/11/20.
// For Seattle University, CPSC 5005
//

#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include "BitStream.h"
#include "HuffNodeMinHeap.h"
#include "HuffNode.h"

class Huffman {
public:
    /**
     * Construct a Huffman encoder/decoder based on the character frequencies in the given sample.
     *
     * @param sample  source for character frequencies
     * @param verbose true if we should display notes to console
     */
    Huffman(std::string sample, bool verbose);

    /**
     * Destructor has to free encodeMap and the Huffman tree.
     */
    ~Huffman();

    // disable copy constructor and assignment operator (I'm just lazy)
    Huffman(const Huffman &other) = delete;
    Huffman &operator=(const Huffman &rhs) = delete;

    /**
     * Encode a sequence of ASCII characters into a compressed bit stream.
     *
     * @param uncompressed stream of ASCII characters to encode
     * @return encoded bit stream of given uncompressed character stream
     */
    BitStream *encode(std::string uncompressed);

    /**
     * Decode a bit stream that was compressed with this (or equivalent)
     * Huffman encoder/decoder.
     *
     * @param compressed bit stream returned from this (or similar) encode method
     * @return the original text stream that generated this compressed bit stream
     */
    std::string decode(BitStream *compressed);

private:
    static const int BIT_PATTERNS_PER_BYTE = 256; // assuming ASCII 8-bit
    bool verbose;
    HuffNode *huffmanTree;
    BitStream *encodeMap;

    /**
     * Use a priority queue to build the Huffman decoding tree.
     * NOTE: This is the quintessential concept of Huffman.
     *
     * @param counts table of frequencies for each ASCII character (indexed
     *               by character)
     */
    void makeHuffmanTree(int *counts);

    /**
     * Recursively create the encoding map.
     * Once this is run, this.encodeMap[character] is the bit stream to use
     * for that character.
     */
    void populateMap();

    /**
     * Recursive helper for populateMap().
     *
     * @param curr   current node in the Huffman tree (this.huffmanTree)
     * @param prefix bit stream so far to get down to this node
     */
    void populateMap(HuffNode *curr, BitStream &prefix);

    /**
     * Count the frequencies of each ASCII character in the given sample text.
     * This uses the trick of using the ASCII number to index into an array
     * of all possible (256) ASCII values. (A kind of hash table, right?)
     *
     * @param sample text to count frequencies in
     * @return an array of frequencies indexed by the character's ordinal value
     */
    static int *count(std::string sample);
};
