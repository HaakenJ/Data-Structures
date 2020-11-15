//
// Created by Kevin Lundeen on 11/11/20.
// For Seattle University, CPSC 5005
//

#pragma once

#include <stdexcept>
#include <sstream>
#include "HuffNode.h"

/**
 * This MinHeap class implements a Priority Queue ADT of HuffNode.
 * (Based on Session7.Heap.)
 *
 * The priority queue enqueues items in any order, but the dequeue order
 * is determined by the natural ordering of the elements. The item dequeued
 * is always the minimum value of all the items currently in the priority
 * queue.
 *
 * A priority queue does not permit null elements.
 *
 * Note that some priority queue authors would call our 'enqueue' method 'offer'
 * and our 'dequeue' method 'poll'. And Carrano calls them 'add' and 'remove'.
 *
 * A priority queue has the same methods as a queue but the semantics of dequeue
 * (and correspondingly, peek) are different.
 */
class HuffNodeMinHeap {
public:
    /**
     * Simple constructor.
     */
    HuffNodeMinHeap();

    /**
     * Destructor.
     */
    ~HuffNodeMinHeap();

    /**
     * Copy constructor (deep copy).
     * @param other source of this object's data
     */
    HuffNodeMinHeap(const HuffNodeMinHeap &other);

    /**
     * Assignment operator (deep copy).
     * @param rhs source of this object's data
     * @return *this
     */
    HuffNodeMinHeap &operator=(const HuffNodeMinHeap &rhs);

    /**
     * Add an element to the queue. Items need not be unique.
     * @param newItem to add to the priority queue
     */
    void enqueue(HuffNode *newItem);

    /**
     * Remove the least element from the queue.
     * @return the least element
     */
    HuffNode *dequeue();

    /**
     * Check if there are any elements in the queue.
     * @return true if there are no elements
     */
    bool empty() const;

    /**
     * Fetch the element that would be returned by dequeue.
     * @return the least element
     */
    HuffNode *peek() const;

    /**
     * Printable contents of the given priority queue.
     */
    std::string toString();

private:
    static const int ROOT = 0;
    static const int INITIAL_CAPACITY = 17;
    int size;
    int capacity;
    HuffNode **data;

    /**
     * The value at data[index] may violate the heap invariants by being too low.
     * If so, fix it by swapping with ancestors as necessary.
     *
     * @param child of data that may be too low relative to parent (and further
     *              ancestors)
     */
    void percolateUp(int child);

    /**
     * The value at data[index] may violate the heap invariants by being too
     * high. If so, fix it by swapping with descendants as necessary.
     *
     * @param parent of data that may be too high relative to children (and
     *              further descendants)
     */
    void percolateDown(int parent);

    /**
     * Get the index of the parent of a given node in this heap.
     * Does not check if parent index is the root (parent(0) returns 0).
     *
     * @param childIndex child address
     * @return index of the left child of parentIndex in the data array
     */
    static int parent(int childIndex);

    /**
     * Check if the given node has a left child.
     *
     * @param parentIndex parent address
     * @return true if the left child of parentIndex is a current member of the
     *         heap
     */
    bool hasLeft(int parentIndex) const;

    /**
     * Check if the given node has a right child.
     *
     * @param parentIndex parent address
     * @return true if the right child of parentIndex is a current member of
     *         the heap
     */
    bool hasRight(int parentIndex) const;

    /**
     * Get the index of the left child of a given node in this heap.
     * Does not check if the child is a current member of this heap.
     *
     * @param parentIndex parent address
     * @return index of the left child of parentIndex in the data array
     */
    static int left(int parentIndex);

    /**
     * Get the index of the right child of a given node in this heap.
     * Does not check if the child is a current member of this heap.
     *
     * @param parentIndex parent address
     * @return index of the right child of parentIndex in the data array
     */
    static int right(int parentIndex);
};
