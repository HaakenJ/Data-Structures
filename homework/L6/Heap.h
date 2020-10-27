//
// Created by Kevin Lundeen on 10/21/20.
// Seattle University, CPSC 5005, Session 7
//

#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <bits/stdc++.h>

/**
 * This Heap class implements a Priority Queue ADT of integers
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
template<typename T>
class Heap {
public:
    /**
     * Default ctor
     */
     Heap();

    /**
     * All-at-once constructor.
     * This is more efficient than enqueueing them all individually.
     * @param data  array of integers to enqueue
     * @param size  number of integers in data
     */
    Heap(const T *data, int size);

    /**
     * Add an element to the queue. Items need not be unique.
     * @param newItem to add to the priority queue
     */
    void enqueue(T newItem);

    /**
     * Remove the least element from the queue.
     * @return the least element
     */
    T dequeue();

    /**
     * Check if there are any elements in the queue.
     * @return true if there are no elements
     */
    bool empty() const;

    /**
     * Fetch the element that would be returned by dequeue.
     * @return the least element
     */
    T peek() const;

    /**
     * Sort the given array in place in ascending order using heapsort,
     * O(n log n).
     *
     * @param data to be sorted
     * @param size number of items in data
     */
    static void heapsort(T *data, int size);

    /**
     * Check if the heap invariants are true for every node.
     *
     * @return true if every node is correct
     */
    bool isValid();

private:
    std::vector<T> data;

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

template<typename T>
Heap<T>::Heap() = default;

template<typename T>
Heap<T>::Heap(const T *data, int size) {
    for (int i = 0; i < size; i++)
        this->data.push_back(data[i]);
    heapify();
}

template<typename T>
void Heap<T>::enqueue(T newItem) {
    data.push_back(newItem);
    percolateUp(data.size() - 1);
}

template<typename T>
T Heap<T>::dequeue() {
    T ret = peek();

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

template<typename T>
bool Heap<T>::empty() const {
    return data.size() == 0;
}

template<typename T>
T Heap<T>::peek() const {
    if (empty())
        throw std::invalid_argument("empty queue");
    return data[0];
}

template<typename T>
void Heap<T>::heapify() {
    // starting at last parent, work backwards to root, causing every subtree
    // to be made into a heap
    for (int index = data.size() / 2; index >= 0; index--)
        percolateDown(index);
}

template<typename T>
void Heap<T>::percolateUp(int index) {
    if (index > 0) {
        int p = parent(index);
        // if in violation of invariants, swap it up
        if (data[p] > data[index]) {
            T temp = data[p];
            data[p] = data[index];
            data[index] = temp;
            percolateUp(p);
        }
    }
}

template<typename T>
void Heap<T>::percolateDown(int index) {
    if (hasLeft(index)) {
        // get minimum of the one or two children
        int child = left(index);
        if (hasRight(index)) {
            int r = right(index);
            if (data[r] < data[child])
                child = r;
        }
        // if in violation of invariants, swap it down
        if (data[child] < data[index]) {
            T temp = data[index];
            data[index] = data[child];
            data[child] = temp;
            percolateDown(child);
        }
    }
}

template<typename T>
bool Heap<T>::hasLeft(int parentIndex) const {
    return left(parentIndex) < data.size();
}

template<typename T>
bool Heap<T>::hasRight(int parentIndex) const {
    return right(parentIndex) < data.size();
}

template<typename T>
int Heap<T>::parent(int childIndex) {
    return (childIndex - 1) / 2;
}

template<typename T>
int Heap<T>::left(int parentIndex) {
    return parentIndex * 2 + 1;
}

template<typename T>
int Heap<T>::right(int parentIndex) {
    return left(parentIndex) + 1;
}

template<typename T>
void Heap<T>::heapsort(T *data, int size) {
    Heap heap(data, size);
    // dequeueing everything will get it in ascending order
    for (int i = 0; i < size; i++)
        data[i] = heap.dequeue();
}

template<typename T>
bool Heap<T>::isValid() {
    for (int i = data.size() - 1; i > 0; i--) {
        if (data[parent(i)] > data[i])
            return false;
    }
    return true;
}
