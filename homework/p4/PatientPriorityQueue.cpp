//
// Created by Haake on 11/2/2020.
//

#include "PatientPriorityQueue.h"

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
    return data.empty();
}

const Patient & PatientPriorityQueue::peek() const {
    if (empty())
        throw std::invalid_argument("empty queue");
    return data[0];
}

const Patient &PatientPriorityQueue::peek(int index) const {
    if (empty())
        throw std::invalid_argument("empty queue");
    return data[index];
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
            if (data[r].compareTo(data[child]) < 0)
                child = r;
        }
        // if in violation of invariants, swap it down
        if (data[child].compareTo(data[index]) < 0) {
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
        if (data[parent(i)].compareTo(data[i]) > 0)
            return false;
    }
    return true;
}

int PatientPriorityQueue::size() const {
    return data.size();
}
