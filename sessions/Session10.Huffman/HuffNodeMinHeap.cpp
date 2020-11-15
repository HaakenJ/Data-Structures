//
// Created by Kevin Lundeen on 11/11/20.
// For Seattle University, CPSC 5005
//

#include "HuffNodeMinHeap.h"
using namespace std;

HuffNodeMinHeap::HuffNodeMinHeap() {
    size = 0;
    capacity = INITIAL_CAPACITY;
    data = new HuffNode *[capacity];
}

HuffNodeMinHeap::~HuffNodeMinHeap() {
    delete[] data;
}

HuffNodeMinHeap::HuffNodeMinHeap(const HuffNodeMinHeap &other) {
    size = other.size;
    capacity = other.capacity;
    data = new HuffNode *[capacity];
    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

HuffNodeMinHeap &HuffNodeMinHeap::operator=(const HuffNodeMinHeap &rhs) {
    if (&rhs != this) {
        delete[] data;
        size = rhs.size;
        capacity = rhs.capacity;
        data = new HuffNode *[capacity];
        for (int i = 0; i < size; i++)
            data[i] = rhs.data[i];
    }
    return *this;
}

void HuffNodeMinHeap::enqueue(HuffNode *newItem) {
    if (size == capacity) {
        capacity *= 2;
        HuffNode **oldData = data;
        data = new HuffNode *[capacity];
        for (int i = 0; i < size; i++)
            data[i] = oldData[i];
    }
    data[size++] = newItem;
    percolateUp(size - 1);
}

HuffNode *HuffNodeMinHeap::dequeue() {
    HuffNode *ret = peek();
    data[0] = data[--size];
    percolateDown(ROOT);
    return ret;
}

bool HuffNodeMinHeap::empty() const {
    return size == 0;
}

HuffNode *HuffNodeMinHeap::peek() const {
    if (empty())
        throw invalid_argument("empty queue");
    return data[0];
}

string HuffNodeMinHeap::toString() {
    ostringstream out;
    out << "\npq: " << endl;
    for (int i = 0; i < size; i++)
        out << "\t" << data[i]->toString() << endl;
    return out.str();
}

void HuffNodeMinHeap::percolateUp(int child) {
    if (child > 0) {
        int p = parent(child);
        // if in violation of invariants, swap it up
        if (data[child]->frequency < data[p]->frequency) {
            swap(data[p], data[child]);
            percolateUp(p);
        }
    }
}

void HuffNodeMinHeap::percolateDown(int parent) {
    if (hasLeft(parent)) {
        // get minimum of the one or two children
        int child = left(parent);
        if (hasRight(parent)) {
            int r = right(parent);
            if (data[r]->frequency < data[child]->frequency)
                child = r;
        }
        // if in violation of invariants, swap it down
        if (data[child]->frequency < data[parent]->frequency) {
            swap(data[parent], data[child]);
            percolateDown(child);
        }
    }
}

int HuffNodeMinHeap::parent(int childIndex) {
    return (childIndex - 1) / 2;
}

bool HuffNodeMinHeap::hasLeft(int parentIndex) const {
    return left(parentIndex) < size;
}

bool HuffNodeMinHeap::hasRight(int parentIndex) const {
    return right(parentIndex) < size;
}

int HuffNodeMinHeap::left(int parentIndex) {
    return parentIndex * 2 + 1;
}

int HuffNodeMinHeap::right(int parentIndex) {
    return left(parentIndex) + 1;
}
