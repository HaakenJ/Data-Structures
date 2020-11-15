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
    /**
     * take in word
     * Update total word counts
     * if word does not exist
     *     add to hash table
     *     set word count to 1
     *     update unique word count
     * else
     *     increment count of given word in has table
     * return give word count
     */
    int result = 0;
    totalWordCount++;
    if (getWordCount(word) == 0) {
        int index = hashWord(word);
        table[index] = new HashEntry(word);
        uniqueWordCount++;
        result = 1;
    }
    else {
        int index = hashWord(word);
        HashEntry* curr = table[index];
        while (curr->value != word)
            curr = curr->next;
        result = curr->wordCount + 1;
        delete curr;
    }
    return result;
}

void WordCounter::removeWord(const std::string &word) {
    /**
     * take in word
     * if the word doesn't exist throw invalid_argument
     * remove word node from hash table
     * reduce total word count and unique word count
     */
}

int WordCounter::getWordCount(const std::string &word) const {
    /**
     * if word in list
     *     return count of that word
     * else
     *     return 0;
     */
    return 0;
}

double WordCounter::getLoadFactor() const {
    // return uniqueWordCount / bucketCount;
    return 0;
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

int WordCounter::hashWord(const std::string &word) {
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
            return true;
    }

    return false;
}

int WordCounter::getNextPrime(int n) {
    while (!isPrime(n))
        n++;

    return n;
}

