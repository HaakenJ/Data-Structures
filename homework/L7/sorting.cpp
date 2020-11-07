//
// Created by Kevin Lundeen on 10/29/20.
// For Seattle University, CPSC 5005, Session 8.
//

#include <iostream>
#include <chrono>
#include "RandomArray.h"
#include "Sort.h"
using namespace std;
using namespace std::chrono;

/**
 * Print out a line with the given array and whether or not it is sorted.
 * @param title  caption to print before array
 * @param ra     array to print and check
 */
void printAndTest(string title, RandomArray &ra) {
    cout << title << ": "
         << ra.toString()
         << (ra.isSorted() ? "" : "not " ) << "sorted"
         << endl;
}

/**
 * Silly O(n!) brute force approach to sorting.
 * Don't try this with much more than 10-12 elements if you ever want it to
 * finish!
 * @param ra array to sort
 */
void brutesort(RandomArray &ra) {
    while (!ra.isSorted())
        ra.shuffle();
}

/**
 * Main entry point of sorting tests.
 * @return EXIT_SUCCESS
 */
int main() {

    high_resolution_clock::time_point start, end;
    milliseconds ms;


    // FIXME: what you want to time goes here


    RandomArray x(10000);
    printAndTest("a random array  ", x);

    // introspective (C++ STL)
    cout << endl;

    start = high_resolution_clock::now();
    Sort<int>::introspective(x.array, x.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);  // converts nanoseconds to ms
    cout << "elapsed time: " << ms.count() << "ms" << endl;

    printAndTest("introsorted     ", x);
    Sort<int>::introspective(x.array, x.size);
    printAndTest("sort of sorted  ", x);
    x.shuffle();
    printAndTest("reshuffled      ", x);

    // quicksort
    cout << endl;

    start = high_resolution_clock::now();
    Sort<int>::quick(x.array, x.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);  // converts nanoseconds to ms
    cout << "elapsed time: " << ms.count() << "ms" << endl;

    printAndTest("quicksorted     ", x);
    Sort<int>::quick(x.array, x.size);
    printAndTest("sort of sorted  ", x);
    x.shuffle();
    printAndTest("reshuffled      ", x);

    // merge sort
    cout << endl;

    start = high_resolution_clock::now();
    Sort<int>::merge(x.array, x.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);  // converts nanoseconds to ms
    cout << "elapsed time: " << ms.count() << "ms" << endl;

    printAndTest("merge sorted    ", x);
    Sort<int>::merge(x.array, x.size);
    printAndTest("sort of sorted  ", x);
    x.shuffle();
    printAndTest("reshuffled      ", x);

    // heap sort
    cout << endl;

    start = high_resolution_clock::now();
    Sort<int>::heap(x.array, x.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);  // converts nanoseconds to ms
    cout << "elapsed time: " << ms.count() << "ms" << endl;

    printAndTest("heap sorted     ", x);
    Sort<int>::heap(x.array, x.size);
    printAndTest("sort of sorted  ", x);
    x.shuffle();
    printAndTest("reshuffled      ", x);

    // insertion sort
    cout << endl;

    start = high_resolution_clock::now();
    Sort<int>::insertion(x.array, x.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);  // converts nanoseconds to ms
    cout << "elapsed time: " << ms.count() << "ms" << endl;

    printAndTest("insertion sorted", x);
    Sort<int>::insertion(x.array, x.size);
    printAndTest("sort of sorted  ", x);
    x.shuffle();
    printAndTest("reshuffled      ", x);

    // selection sort
    cout << endl;

    start = high_resolution_clock::now();
    Sort<int>::selection(x.array, x.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);  // converts nanoseconds to ms
    cout << "elapsed time: " << ms.count() << "ms" << endl;

    printAndTest("selection sorted", x);
    x.shuffle();
    printAndTest("reshuffled      ", x);

    // bubble sort
    cout << endl;

    start = high_resolution_clock::now();
    Sort<int>::bubble(x.array, x.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);  // converts nanoseconds to ms
    cout << "elapsed time: " << ms.count() << "ms" << endl;

    printAndTest("bubble sorted   ", x);
    x.shuffle();
    printAndTest("reshuffled      ", x);


    // brute sort!
    if (x.size <= 12) {
        cout << endl;

        start = high_resolution_clock::now();
        brutesort(x);  // O(n!)
        end = high_resolution_clock::now();
        ms = duration_cast<milliseconds>(end - start);  // converts nanoseconds to ms
        cout << "elapsed time: " << ms.count() << "ms" << endl;

        printAndTest("brutesorted     ", x);
    }


    return EXIT_SUCCESS;
}
