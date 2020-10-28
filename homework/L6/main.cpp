//
// Created by Kramer Johnson on 10/26/20.
// Seattle University, CPSC 5910 03 Fall 2020
//
// Build off MinHeap non-template tests
// by Kevin Lundeen
//

#include <iostream>
#include "MaxHeap.h"

using namespace std;

string tf(bool cond) {
    return cond ? "true" : "false";
}

template<typename T>
void heapTest(T *data, int size) {
    MaxHeap<int> heap1;
    MaxHeap<int> heap2;

    // add a bunch of things
    cout << "Empty heap1: " << tf(heap1.empty()) << endl;
    cout << "Empty heap2: " << tf(heap2.empty()) << endl;
    for (int i = 0; i < size; i++) {
        heap1.enqueue(data[i]);
        heap2.enqueue(data[i]);
        if (i % 4 == 0)
            heap1.dequeue(); // so we can get some dequeues into the mix
    }
    cout << "Filled 1: " << tf(!heap1.empty()) << endl;
    cout << "Heap1 valid: " << tf(heap1.isValid()) << endl;
    cout << "Filled 2: " << tf(!heap2.empty()) << endl;
    cout << "Heap2 valid: " << tf(heap2.isValid()) << endl;
}

template<typename T>
void testDequeue(MaxHeap<T> heap) {
    // take them out (and check peek at the same time)
    while (!heap.empty()) {
        T prev = heap.peek();
        if (prev != heap.dequeue()) {
            cout << "peek != dequeue FAIL!!" << endl;
            return;
        }
    }
}

template<typename T>
void heapifyTest(T *data, int size) {
    MaxHeap<T> heap(data, size);
    cout << "Heapify test: " << (heap.isValid() ? "valid" : "INVALID") << endl;
    testDequeue(heap);
}

template<typename T>
void heapsortTest(T *data, int size, bool print) {
    MaxHeap<T>::heapsort(data, size);
    int prev = INT_MIN;
    if (print) {
        cout << "sorted: " << endl;
        for (int i = 0; i < size; i++) {
            if (data[i] < prev) {
                cout << "FAILED" << endl;
                return;
            }
            cout << data[i] << " ";
            prev = data[i];
        }

        cout << endl;
    }
}

int main() {
    enum Importance {
        VERY = 20, SOMEWHAT = 9, BLEH = 0, HARDLY = -3, UNIMPORTANT = -10
    };

    int intData[] = {15, 34, 23, 53, 23, 11, 223, 43, 56, 99, 1, 0, 2, 88};
    double dblData[] = {5.0, 23.0, 66.0, 234.2, 5.1, 5.2, 5.3, 66.6, 93.0, 52.9};
    Importance impData[] = {UNIMPORTANT, HARDLY, BLEH, SOMEWHAT, VERY, UNIMPORTANT, UNIMPORTANT};

    cout << "**** Int MaxHeap Tests ****" << endl;
    heapTest<int>(intData,14);
    heapifyTest<int>(intData, 14);
    heapsortTest<int>(intData, 14, true);
    cout << endl;

    cout << "**** Double MaxHeap Tests ****" << endl;
    heapTest<double>(dblData,10);
    heapifyTest<double>(dblData, 10);
    heapsortTest<double>(dblData, 10, true);
    cout << endl;

    cout << "**** Enum MaxHeap Tests ****" << endl;
    heapTest<Importance>(impData,7);
    heapifyTest<Importance>(impData, 7);
    heapsortTest<Importance>(impData, 7, true);

    return EXIT_SUCCESS;
}
