//
// Created by Kevin Lundeen on 11/11/20.
// For Seattle University, CPSC 5005
//

#pragma once

#include <string>
#include <list>
#include <sstream>

/**
 * Class to handle the bit streams for Huffman.
 * This class is not very efficient, but is sufficient for demonstrating Huffman.
 * It is implemented using java.util's LinkedList of Boolean as a Queue.
 * Methods:
 * - Constructors (one taking a String that is interpreted as a series
 *   of bits)
 * - append(bit)
 * - append(bitstream)
 * - cloneAndAppend(bit)
 * - nextBit()
 * - empty()
 * - size()
 */
class BitStream {
public:
    /**
     * Empty bitstream.
     */
    BitStream() {}

    /**
     * Bitstream initially made up of ASCII characters from a String.
     *
     * @param s initial 8-bit ASCII characters whose bits are to be enqueued in this bit stream
     */
    BitStream(std::string s);

    /**
     * Check if this bitstream is empty.
     *
     * @return true if empty
     */
    bool empty() const;

    /**
     * Enqueue a single bit.
     *
     * @param bit true for 1, false for 0
     */
    void append(bool bit);

    /**
     * Enqueue all the bits from another bit stream.
     * The bits from suffix will be enqueued in order without dequeueing from suffix.
     *
     * @param suffix another bit stream
     */
    void append(const BitStream &suffix);

    /**
     * Dequeue the next bit
     *
     * @return the next bit (true for 1, false for 0)
     */
    bool nextBit();

    /**
     * Create a clone of this bit stream and append the given bit to it.
     *
     * @param bit to append to cloned bit stream
     * @return cloned bit stream with bit appended to it
     */
    BitStream cloneAndAppend(bool bit) const;

    /**
     * Get a string representation of all the 0's and 1's.
     * @return printable string
     */
    std::string toString() const;

    /**
     * Number of bits remaining in this bit stream.
     *
     * @return number of bits
     */
    int size() const;

private:
    /**
     * Store a queue of bits (bool).
     * We'll use a doubly-linked list from STL which supports the queue ADT.
     */
    std::list<bool> bits;
};
