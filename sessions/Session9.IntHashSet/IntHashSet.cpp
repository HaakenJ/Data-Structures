//
// Created by Kevin Lundeen on 11/5/20.
//

#include <stdexcept>
#include "IntHashSet.h"
using namespace std;

IntHashSet::IntHashSet() {
    for (int bucket = 0; bucket < CAPACITY; bucket++)
        table[bucket] = EMPTY;
}

bool IntHashSet::has(int key) const {
    int bucket = hash(key) % CAPACITY;
    // skip over entries for other keys and TOMBSTONEs
    while (table[bucket] != key && table[bucket] != EMPTY)
        bucket = next(bucket);
    return table[bucket] == key;
}

int IntHashSet::hash(int key) {
    return abs(key * 269723737);  // make sure we return between 0..MAX_INT
}

int IntHashSet::next(int bucket) const {
    return (bucket + 1) % CAPACITY;
}

void IntHashSet::add(int key) {
    if (key < 0)
        throw invalid_argument("this set doesn't allow negatives");
    int bucket = hash(key) % CAPACITY;
    // skip over entries for other keys (find first EMPTY or TOMBSTONE)
    while (table[bucket] >= 0 && table[bucket] != key)
        bucket = next(bucket);
    table[bucket] = key;
}

void IntHashSet::remove(int key) {
    int bucket = hash(key) % CAPACITY;
    // skip over entries for other keys and TOMBSTONEs
    while (table[bucket] != key && table[bucket] != EMPTY)
        bucket = next(bucket);
    if (table[bucket] == EMPTY)
        return;
    if (table[next(bucket)] != EMPTY)
        table[bucket] = TOMBSTONE;
    else
        table[bucket] = EMPTY;
}

bool IntHashSet::empty() const {
    // FIXME: wouldn't this be better to be a data member so this is faster?
    for (int bucket = 0; bucket < CAPACITY; bucket++)
        if (table[bucket] >= 0)
            return false;
    return true;
}

int IntHashSet::size() const {
    int count = 0;
    // FIXME: wouldn't this be better to be a data member so this is faster?
    for (int bucket = 0; bucket < CAPACITY; bucket++)
        if (table[bucket] >= 0)
            count++;
    return count;
}
