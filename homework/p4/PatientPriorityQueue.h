//
// Created by Kramer Johnson on 10/26/20.
// Seattle University, CPSC 5910 03 Fall 2020
// kjohnson5@seattleu.edu
//
// Build off MinHeap non-template implementation
// by Kevin Lundeen
//

#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Patient.h"

/**
 * This PatientPriorityQueue class implements a Priority Queue ADT of integers
 *
 * The priority queue enqueues items in any order, but the dequeue order
 * is determined by the natural ordering of the elements. The item dequeued
 * is always the maximum value of all the items currently in the priority
 * queue.
 */
class PatientPriorityQueue {
public:
    /**
     * Default ctor
     */
    PatientPriorityQueue();

    /**
     * Add an element to the queue. Items need not be unique.
     * @param newItem to add to the priority queue
     */
    void enqueue(const Patient &newItem);

    /**
     * Remove the greatest element from the queue.
     * @return the greatest element
     */
    Patient dequeue();

    /**
     * Check if there are any elements in the queue.
     * @return true if there are no elements
     */
    bool empty() const;

    /**
     * Fetch the element that would be returned by dequeue.
     * @return the least element
     */
    const Patient &peek() const;

    /**
     * Check if the heap invariants are true for every node.
     *
     * @return true if every node is correct
     */
    bool isValid();

private:
    std::vector<Patient> data;

    /**
     * The value at data[index] may violate the heap invariants by being too low.
     * If so, fix it by swapping with ancestors as necessary.
     *
     * @param index of data that may be too low relative to parent (and further
     *              ancestors)
     */
    void percolateUp(int index);

    /**
     * The value at data[index] may violate the heap invariants by being too
     * high. If so, fix it by swapping with descendants as necessary.
     *
     * @param index of data that may be too high relative to children (and
     *              further descendants)
     */
    void percolateDown(int index);

    /**
     * Construct a heap from arbitrarily-ordered elements in the data array.
     */
    void heapify();

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

PatientPriorityQueue::PatientPriorityQueue() = default;

void PatientPriorityQueue::enqueue(const Patient &newItem) {
    data.push_back(newItem);
    percolateUp(data.size() - 1);
}

Patient PatientPriorityQueue::dequeue() {
    Patient ret = peek();

    // get last val in heap, copy value to index 0 and decrease size
    data[0] = data[data.size() - 1];
    data.pop_back();
    // NOTE: add this to sort in place: data[size] = ret;

    // create a recursive helper, percolateDown,
    // that allows you move the removed val
    // in the right place
    percolateDown(0);
    return ret;
}

bool PatientPriorityQueue::empty() const {
    return data.size() == 0;
}

const Patient & PatientPriorityQueue::peek() const {
    if (empty())
        throw std::invalid_argument("empty queue");
    return data[0];
}

void PatientPriorityQueue::heapify() {
    // starting at last parent, work backwards to root, causing every subtree
    // to be made into a heap
    for (int index = data.size() / 2; index >= 0; index--)
        percolateDown(index);
}

void PatientPriorityQueue::percolateUp(int index) {
    if (index > 0) {
        int p = parent(index);
        // if in violation of invariants, swap it up
        if (data[p].compareTo(data[index]) > 0) {
            // TODO: figure out swap function or make your own
            Patient temp = data[p];
            data[p] = data[index];
            data[index] = temp;
            percolateUp(p);
        }
    }
}

void PatientPriorityQueue::percolateDown(int index) {
    if (hasLeft(index)) {
        // get minimum of the one or two children
        int child = left(index);
        if (hasRight(index)) {
            int r = right(index);
            if (data[r] > data[child])
                child = r;
        }
        // if in violation of invariants, swap it down
        if (data[child] > data[index]) {
            // TODO: figure out swap function or make your own
            Patient temp = data[index];
            data[index] = data[child];
            data[child] = temp;
            percolateDown(child);
        }
    }
}

bool PatientPriorityQueue::hasLeft(int parentIndex) const {
    return left(parentIndex) < data.size();
}

bool PatientPriorityQueue::hasRight(int parentIndex) const {
    return right(parentIndex) < data.size();
}

int PatientPriorityQueue::parent(int childIndex) {
    return (childIndex - 1) / 2;
}

int PatientPriorityQueue::left(int parentIndex) {
    return parentIndex * 2 + 1;
}

int PatientPriorityQueue::right(int parentIndex) {
    return left(parentIndex) + 1;
}

bool PatientPriorityQueue::isValid() {
    for (int i = data.size() - 1; i > 0; i--) {
        if (data[parent(i)] < data[i])
            return false;
    }
    return true;
}
