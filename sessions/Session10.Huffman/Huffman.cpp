//
// Created by Kevin Lundeen on 11/11/20.
// For Seattle University, CPSC 5005
//

#include <iostream>
#include "Huffman.h"

using namespace std;

Huffman::Huffman(string sample, bool verbose) {
    this->verbose = verbose;
    int *counts = count(sample);
    makeHuffmanTree(counts);
    delete[] counts;
    encodeMap = new BitStream[BIT_PATTERNS_PER_BYTE];
    populateMap();
}

Huffman::~Huffman() {
    delete[] encodeMap;
    HuffNode::clear(huffmanTree);
}

BitStream *Huffman::encode(string uncompressed) {
    BitStream *bitStream = new BitStream();
    // The encodeMap already knows the bit streams for each ASCII
    // character, so just tack them together
    for (char s : uncompressed)
        bitStream->append(encodeMap[s]);
    return bitStream;
}

string Huffman::decode(BitStream *compressed) {
    ostringstream sb;
    HuffNode *curr = huffmanTree;
    while (!compressed->empty()) {
        bool bit = compressed->nextBit();

        if (bit) // if a 1, then go right
            curr = curr->right;
        else  // if a 0, then go left
            curr = curr->left;

        // if we have gotten to a leaf, we have decoded another character, so
        // append it and restart at root
        if (curr->isLeaf()) {
            sb << curr->value;
            curr = huffmanTree; // return to root of tree
        }
    }
    return sb.str();
}

void Huffman::makeHuffmanTree(int *counts) {
    HuffNodeMinHeap pq;

    // Initial queue entries -- only make one-node trees for each used character
    // These will all be LEAF nodes.
    // NOTE: unused characters per the counts array will not be encoded!
    for (int i = 0; i < BIT_PATTERNS_PER_BYTE; i++)
        if (counts[i] > 0) {
            pq.enqueue(new HuffNode(i, counts[i]));
        }

    // combine most frequent pairs until only one tree left
    HuffNode *redLantern = nullptr;
    while (!pq.empty()) {
        if (verbose)
            cout << pq.toString();

        // redLantern is least frequent tree (reference is to Tour de France's Red Lantern jersey)
        // runnerUp is second least frequent tree
        redLantern = pq.dequeue();
        if (pq.empty())
            break; // we now have our one final remaining tree
        HuffNode *runnerUp = pq.dequeue();

        // Put the redLantern tree and the runnerUp tree together into a single tree and put it back on queue
        // This will be an INTERIOR node since it is combining two subtrees.
        pq.enqueue(new HuffNode(redLantern, runnerUp));
    }
    huffmanTree = redLantern;
}

void Huffman::populateMap() {
    BitStream bs;
    populateMap(huffmanTree, bs);
}

void Huffman::populateMap(HuffNode *curr, BitStream &prefix) {
    if (curr != nullptr) {
        // Have we arrived at a LEAF node?
        if (curr->isLeaf()) {
            // If so, make an entry in this.encodeMap for this character.
            encodeMap[curr->value] = prefix;
            if (verbose)
                cout << "encodeMap[" << curr->value << "]: "
                          << prefix.toString() << endl;
        } else {
            // recurse both left and right
            // false is a 0 bit
            BitStream leftSide = prefix.cloneAndAppend(false);
            populateMap(curr->left, leftSide);
            // true is a 1 bit
            BitStream rightSide = prefix.cloneAndAppend(true);
            populateMap(curr->right, rightSide);
        }
    }
}

int *Huffman::count(string sample) {
    int *counts = new int[BIT_PATTERNS_PER_BYTE];
    for (char c : sample)
        counts[c]++;
    return counts;
}
