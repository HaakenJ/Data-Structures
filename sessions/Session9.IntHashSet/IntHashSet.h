//
// Created by Kevin Lundeen on 11/5/20.
//

#pragma once

/**
 * Is a Set ADT of nonnegative integers using a hash table with linear probing.
 */
class IntHashSet {
public:
    IntHashSet();
    bool has(int key) const;
    void add(int key);
    void remove(int key);
    bool empty() const;
    int size() const;
private:
    static const int EMPTY = -1;
    static const int TOMBSTONE = -2;
    static const int CAPACITY = 13;  // Usually you want a prime number here
    //int count;
    int table[CAPACITY];

    static int hash(int key);
    int next(int bucket) const;
};
