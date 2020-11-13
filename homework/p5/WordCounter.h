//
// Created by Haake on 11/12/2020.
//

#ifndef P5_WORDCOUNTER_H
#define P5_WORDCOUNTER_H

#include<iostream>

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
    WordCounter(int size);

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
     */
    void removeWord(const std::string &word);

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
    static const int DEFAULT_SIZE = 101;
    int uniqueWordCount;
    int totalWordCount;
    int capacity;

    struct HashEntry {
        int key;
        std::string value;
        HashEntry *next;

        HashEntry(int newKey, std::string &newVal,
                  HashEntry *newNext=nullptr) {
            key   = newKey;
            value = newVal;
            next  = newNext;
        }
    };

    HashEntry** table;

    int hashWord(const std::string &word);

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
};


#endif //P5_WORDCOUNTER_H
