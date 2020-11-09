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

void testAndTime(int n) {
    // create random array of n elements
    RandomArray ra(n);

    // create timing objects
    high_resolution_clock::time_point start, end;
    milliseconds ms;

    cout << "sorting " << n << " values:" << endl;

    // time and display quicksort
    start = high_resolution_clock::now();
    Sort<int>::quick(ra.array, ra.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "quicksort elapsed time: ";
    cout << ms.count() << "ms" << endl;

    ra.shuffle(); // reshuffle array

    // time and display heap sort
    start = high_resolution_clock::now();
    Sort<int>::heap(ra.array, ra.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "heap sort elapsed time: ";
    cout << ms.count() << "ms" << endl;

    ra.shuffle();

    // time and display merge sort
    start = high_resolution_clock::now();
    Sort<int>::merge(ra.array, ra.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "merge sort elapsed time: ";
    cout << ms.count() << "ms" << endl;

    ra.shuffle();

    // time and display introsort
    start = high_resolution_clock::now();
    Sort<int>::introspective(ra.array, ra.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "STL's introsort elapsed time: ";
    cout << ms.count() << "ms" << endl;

    ra.shuffle();

    // time and display insertion sort
    start = high_resolution_clock::now();
    Sort<int>::insertion(ra.array, ra.size);
    end = high_resolution_clock::now();
    ms = duration_cast<milliseconds>(end - start);
    cout << "insertion sort elapsed time: ";
    cout << ms.count() << "ms" << endl;

}

/**
 * Main entry point of sorting tests.
 * @return EXIT_SUCCESS
 */
int main() {

    testAndTime(40000);
    cout << endl;
    testAndTime(80000);
    cout << endl;
    testAndTime(160000);


    return EXIT_SUCCESS;
}
