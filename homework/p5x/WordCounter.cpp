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
    if (isPrime(size))
        capacity = size;
    else
        capacity = getNextPrime(size);
    std::cout << capacity << std::endl;
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
            this->table[i] = rhs.table[i];
        }
    }
    return *this;
}

int WordCounter::addWord(const std::string &word) {
    int result = 0;
    totalWordCount++;

    std::cout << "Inserting: " << word << std::endl;

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

    std::cout << "LoadFactor: " << getLoadFactor() << std::endl;
    // double size of table if load factor is too large
    if (getLoadFactor() > 0.75)
        doubleSize();


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

    // if load factor is too small, cut size in half
    if (getLoadFactor() < 0.30)
        reduceSize();

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

int WordCounter::hashWord(const std::string &word, int size) const {
    std::hash<std::string> h;
    int index = h(word) % size;
    return index;
}

bool WordCounter::isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;

    for (int i = 2; i <= sqrt(n); i++) {
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

void WordCounter::doubleSize() {
    // Update capacity
    int newCapacity = capacity * 2;

    if (!isPrime(newCapacity))
        newCapacity = getNextPrime(newCapacity);

    std::cout << "New Capacity: " << newCapacity << std::endl;

    // Create temp array with new capacity
    auto **temp = new HashEntry*[newCapacity];

    // initialize to nullptr
    for (int i = 0; i < newCapacity; i++)
        temp[i] = nullptr;

    // Copy old values to temp array
    for (int i = 0; i < capacity; i++) {

        if (table[i] != nullptr) {
            HashEntry *curr = table[i];
            while (curr != nullptr) {
                int newAddress = hashWord(curr->value, newCapacity);
                std::cout << "New Address for " << curr->value << " is ";
                std:: cout << newAddress << std::endl;
                if (temp[newAddress] == nullptr)
                    temp[newAddress] = curr;
                else { // temp[newAddress] already has an entry
                    HashEntry *tempCurr = temp[newAddress];
                    while (tempCurr->next != nullptr) // move to last item
                        tempCurr = tempCurr->next;
                    tempCurr->next = curr;  // add table list to end of entry
                }
                curr = curr->next;
            }
        }
    }

    capacity = newCapacity;

    // Deallocate old table
    delete[] table;

    // Reassign old array to new
    table = temp;
}

void WordCounter::reduceSize() {
    // Update capacity
    int newCapacity = capacity /  2;

    if (!isPrime(newCapacity))
        newCapacity = getNextPrime(newCapacity);

    // Create temp array with new capacity
    auto **temp = new HashEntry*[newCapacity];

    // initialize to nullptr
    for (int i = 0; i < newCapacity; i++)
        temp[i] = nullptr;

    // Copy old values to temp array
    for (int i = 0; i < capacity; i++) {
        if (table[i] != nullptr) {
            int newAddress = hashWord(table[i]->value, newCapacity);
            if (temp[newAddress] == nullptr)
                temp[newAddress] = table[i];
            else { // temp[newAddress] already has an entry
                HashEntry *curr = temp[newAddress];
                while (curr->next != nullptr) // move to last item
                    curr = curr->next;
                curr->next = table[i];  // add table list to end of entry
            }
        }
    }

    capacity = newCapacity;

    // Deallocate old memberArray
    delete[] table;

    // Reassign old array to new
    table = temp;
}

