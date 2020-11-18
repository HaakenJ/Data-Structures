//
// Created by Kramer Johnson on 11/12/2020.
// Seattle University CSPC 5901 03 Fall 2020
// Project 5
// kjohnson5@seattleu.edu
//

#include "WordCounter.h"

WordCounter::WordCounter() {
    uniqueWordCount = 0;
    totalWordCount = 0;
    capacity = DEFAULT_SIZE;
    table = new HashEntry*[capacity];

    for (int i = 0; i < capacity; i++)
        table[i] = nullptr;
}

WordCounter::WordCounter(int size) {
    uniqueWordCount = 0;
    totalWordCount = 0;
    capacity = size;
//    if (isPrime(size))
//        capacity = size;
//    else
//        capacity = getNextPrime(size);
    table = new HashEntry*[capacity];
    for (int i = 0; i < capacity; i++)
        table[i] = nullptr;
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
    int result = 0;
    totalWordCount++;
    if (getWordCount(word) == 0) {
        int index = hashWord(word);

        if (table[index] != nullptr) {  // check if bucket is occupied
            HashEntry* temp = table[index];
            table[index] = new HashEntry(word);
            table[index]->next = temp;
        }
        else {
            table[index] = new HashEntry(word);
        }
        uniqueWordCount++;
        result = table[index]->wordCount;
    }
    else {
        int index = hashWord(word);
        HashEntry* curr = table[index];
        while (curr->value != word)
            curr = curr->next;
        result = curr->wordCount + 1;
        curr->wordCount++;
    }
    return result;
}

bool WordCounter::removeWord(const std::string &word) {
    if (getWordCount(word) == 0)
        return false;
    int index = hashWord(word);
    HashEntry* curr = table[index];

    // check if the value is first in list
    if (curr->value == word) {
        totalWordCount = totalWordCount - curr->wordCount;
        table[index] = curr->next;
    }
    else {
        HashEntry* prev = curr;
        while (curr->value != word) {
            prev = curr;
            curr = curr->next;
        }
        totalWordCount = totalWordCount - curr->wordCount;
        prev->next = curr->next;
    }
    uniqueWordCount--;
    return true;
}

int WordCounter::getWordCount(const std::string &word) const {
    int result = 0;
    int index = hashWord(word);
    HashEntry* curr = table[index];
    while (curr != nullptr) {
        if (curr->value == word) {
            result = curr->wordCount;
            break;
        }
        curr = curr->next;
    }
    return result;
}

double WordCounter::getLoadFactor() const {
    return (round(uniqueWordCount * 1000) / 1000.0) / capacity;
}

int WordCounter::getUniqueWordCount() const {
    return uniqueWordCount;
}

int WordCounter::getTotalWordCount() const {
    return totalWordCount;
}

bool WordCounter::empty() const {
    return totalWordCount == 0;
}

int WordCounter::hashWord(const std::string &word) const {
    std::hash<std::string> h;
    int index = h(word) % capacity;
    return index;
}

bool WordCounter::isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;

    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int WordCounter::getNextPrime(int n) {
    while (!isPrime(n))
        n++;

    return n;
}

