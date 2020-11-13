//
// Created by Haake on 11/12/2020.
//

#include "WordCounter.h"

WordCounter::WordCounter() {
    uniqueWordCount = 0;
    totalWordCount = 0;
    capacity = DEFAULT_SIZE;
    table = new HashEntry*[capacity];
}

WordCounter::WordCounter(int size) {
    uniqueWordCount = 0;
    totalWordCount = 0;
    if (isPrime(size))
        capacity = size;
    else
        capacity = getNextPrime(size);
    table = new HashEntry*[capacity];
}

WordCounter::~WordCounter() {
    delete[] table;
}

WordCounter::WordCounter(const WordCounter &other) {
    // Copy data elements
    uniqueWordCount = other.uniqueWordCount;
    totalWordCount = other.totalWordCount;
    capacity = other.capacity;

    // Allocate memory with new capacity
    table = new HashEntry*[capacity];

    // Copy over elements from other
    for (int i = 0; i < capacity; i++) {
        *table[i] = *other.table[i];
    }
}

WordCounter &WordCounter::operator=(const WordCounter &rhs) {
    if (this != &rhs) {
        delete[] this->table;

        // Copy data elements
        this->uniqueWordCount = rhs.uniqueWordCount;
        this->totalWordCount = rhs.totalWordCount;
        this->capacity = rhs.capacity;

        // Allocate memory with new capacity
        this->table = new HashEntry*[capacity];

        // Copy over elements from other
        for (int i = 0; i < capacity; i++) {
            *this->table[i] = *rhs.table[i];
        }
    }
    return *this;
}

int WordCounter::addWord(const std::string &word) {
    return 0;
}

void WordCounter::removeWord(const std::string &word) {

}

int WordCounter::getWordCount(const std::string &word) const {
    return 0;
}

double WordCounter::getLoadFactor() const {
    return 0;
}

int WordCounter::getUniqueWordCount() const {
    return 0;
}

int WordCounter::getTotalWordCount() const {
    return 0;
}

bool WordCounter::empty() const {
    return false;
}

int WordCounter::hashWord(const std::string &word) {
    return 0;
}

bool WordCounter::isPrime(int n) {
    return false;
}

int WordCounter::getNextPrime(int n) {
    return 0;
}

