//
// Created by Kevin Lundeen on 11/11/20.
// For Seattle University, CPSC 5005
//

#pragma once

#include <string>

/**
 * Class to represent the Huffman decoding tree.
 */
class HuffNode {
public:
    HuffNode *left, *right;

    /**
     * frequency of all characters in this subtree
     * for LEAF, the frequency of value
     * for INTERIOR, sum of all descendant LEAF's
     */
    int frequency;

    /**
     * The character stored at this leaf
     * (only used when type is LEAF)
     */
    char value;

    /**
     * Constructor for a LEAF node.
     *
     * @param c    character for this leaf
     * @param freq frequency of c in the sample text
     */
    HuffNode(int c, int freq);

    /**
     * Constructor for an INTERIOR node.
     * Calculates the frequency as the sum of the two children's frequencies.
     *
     * @param left  less frequent subtree
     * @param right more frequent subtree
     */
    HuffNode(HuffNode *left, HuffNode *right);

    /**
     * Check if this is a leaf or an interior node in the Huffman tree
     * @return true if a leaf; false if not
     */
    bool isLeaf() const;

    /**
     * Get a printable string for the this subtree
     * @return printable subtree
     */
    std::string toString() const;

    /**
     * Deallocate the entire given subtree.
     * @param root of subtree to free
     */
    static void clear(HuffNode *root);

private:
    /**
     * Helper method for toString.
     * Recursively show the entire tree at curr and below.
     *
     * @param curr   current node in the Huffman decoding tree
     * @param pre    bit sequence (as a string) so far -- to get to curr
     * @param sb     output string (builder)
     */
    static void
    toStringR(const HuffNode *curr, std::string pre, std::ostringstream &sb);

};
