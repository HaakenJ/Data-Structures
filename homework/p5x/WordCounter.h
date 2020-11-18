//
// Created by Kramer Johnson on 11/12/2020.
// Seattle University CSPC 5901 03 Fall 2020
// Project 5
// kjohnson5@seattleu.edu
//

#ifndef P5_WORDCOUNTER_H
#define P5_WORDCOUNTER_H

#include <iostream>
#include <cmath>

class WordCounter {
public:
    /**
     * Default constructor. Sets size to 101
     */
    WordCounter();

    /**
     * Ctor that takes in a size.
     * Will convert size to next prime number after size
     * if it is not prime
     * @precon     size is a prime number
     * @param size desired size of the word table
     */
    explicit WordCounter(int size);

    /**
     * Destructor
     */
    ~WordCounter();

    /**
     * Copy constructor
     * @param other WordCounter to copy
     */
    WordCounter(const WordCounter &other);

    /**
     * = Assignment overloader
     * @param rhs WordCounter to copy
     * @return    pointer to this WordCounter
     */
    WordCounter &operator=(const WordCounter &rhs);

    /**
     * Adds a word to WordCounter if it does not exist.
     * If it does, increments count of that word
     * @param word
     * @return
     */
    int addWord(const std::string &word);

    /**
     * Removes a word from WordCounter
     * @param word to be removed from the table
     * @return     true if the removal was successful
     *             false if not
     */
    bool removeWord(const std::string &word);

    /**
     * Returns the count of the specified word, or 0 if
     * the word has not yet been encountered
     * @param word to check the count of
     * @return     count of the passed word
     */
    int getWordCount(const std::string &word) const;

    /**
     * Returns the current load factor of the table
     * @return current load factor
     */
    double getLoadFactor() const;

    /**
     * Get the number of unique words encountered
     * @return number of unique words
     */
    int getUniqueWordCount() const;

    /**
     * Get the total number of words encountered
     * @return total number of words
     */
    int getTotalWordCount() const;

    /**
     * Check if the table is empty
     * @return true if table is empty, false otherwise
     */
    bool empty() const;

private:
    static const int DEFAULT_SIZE = 23;
    int uniqueWordCount;
    int totalWordCount;
    int capacity;

    struct HashEntry {
        int wordCount;
        std::string value;
        HashEntry *next;

        explicit HashEntry(std::string newVal,
                  HashEntry *newNext=nullptr) {
            wordCount = 1;
            value = newVal;
            next  = newNext;
        }
    };

    HashEntry** table;

    /**
     * Hash a word to get its address in the table
     * @param word to hash
     * @return     index of the word
     */
    int hashWord(const std::string &word) const;

    /**
     * Hash a word to get its address in the table
     * @param word to hash
     * @param size size of the table to be hashed into
     * @return     index of the word
     */
    int hashWord(const std::string &word, int size) const;

    /**
     * Determines if a number is prime
     * @param n an integer
     * @return  true if n is prime, false otherwise
     */
    static bool isPrime(int n);

    /**
     * Gets the next closest prime number after n
     * @precon  n is not a prime number
     * @param n a non-prime integer
     * @return  the next prime number occuring after n
     */
    static int getNextPrime(int n);

    /**
     * Doubles the size of the hash table
     */
     void doubleSize();

    /**
     * Halves the size of the hash table
     */
     void reduceSize();
};


#endif //P5_WORDCOUNTER_H
