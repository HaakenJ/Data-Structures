//
// Created by Haake on 11/2/2020.
// Seattle University CSPC 5901 03 Fall 2020
// Project 4
// kjohnson5@seattleu.edu
//
// Built off of MaxHeap implementation by
// Kevin Lundeen

#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Patient.h"

/**
 * This PatientPriorityQueue class implements a Priority Queue ADT of Patients
 *
 * The priority queue enqueues items in any order, but the dequeue order
 * is determined by the urgency of a patient's issue. The item dequeued
 * is always the most urgent patient in the queue.
 */
class PatientPriorityQueue {
public:
    /**
     * Default ctor
     */
    PatientPriorityQueue();

    /**
     * Add a Patient to the queue.
     * @param newPatient to add to the priority queue
     */
    void enqueue(const Patient &newPatient);

    /**
     * Remove the most urgent Patient from the queue.
     * @return the most urgent Patient
     */
    Patient dequeue();

    /**
     * Check if there are Patients in the queue.
     * @return true if there are no Patients
     */
    bool empty() const;

    /**
     * Fetch the Patient that would be returned by dequeue.
     * @return the most urgent Patient
     */
    const Patient &peek() const;

    /**
     * Fetch the Patient at an index in the heap.
     * @param index of the Patient to retrieve
     * @return      the least element
     */
    const Patient &peek(int index) const;

    /**
     * Get the number of patients still waiting
     * @return number of patients in queue
     */
     int size() const;

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


