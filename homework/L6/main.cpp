//
// Created by Kevin Lundeen on 10/21/20.
// Seattle University, CPSC 5005, Session 7
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
void drain(MaxHeap<T> heap) {
    // take them out (and check peek at the same time)
    int prev = INT_MAX;
    while (!heap.empty()) {
        if (heap.peek() > prev) {
            cout << "out of order FAIL!!" << endl;
            return;
        }
        prev = heap.peek();
        if (prev != heap.dequeue()) {
            cout << "peek != dequeue FAIL!!" << endl;
            return;
        }
    }
}

template<typename T>
void heapifyTest(T *data, int size) {
    MaxHeap<int> heap(data, size);
    cout << "Heapify test: " << (heap.isValid() ? "valid" : "INVALID") << endl;
    drain(heap);
}

template<typename T>
void heapsortTest(T *data, int size, bool print) {
    MaxHeap<int>::heapsort(data, size);
    int prev = -1;
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
    cout << endl;

    cout << "**** Double MaxHeap Tests ****" << endl;
    heapTest<double>(dblData,10);
    cout << endl;

    cout << "**** Enum MaxHeap Tests ****" << endl;
    heapTest<Importance>(impData,7);



//    heapifyTest(1000, 100);
//    heapsortTest(50, 100, true);

    /* FIXME: do timing in C++ like in this Java version
     * FIXME: this would also require resize() with dynamic array
    long start = System.nanoTime();
    for (int n = 5_000; n < 100_000_000; n *= 2) {
        heapsortTest(n, 100, false);
        long end = System.nanoTime();
        System.out.println(n + ": " + (end - start) / 1000_000_000.0);
        start = end;
    }
    */

    return EXIT_SUCCESS;
}
