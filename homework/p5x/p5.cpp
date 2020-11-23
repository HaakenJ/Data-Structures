//
// Created by Kramer Johnson on 11/12/2020.
// Seattle University CSPC 5901 03 Fall 2020
// Project 5
// kjohnson5@seattleu.edu
//

#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <vector>
#include "WordCounter.h"
#include "English.h"


using namespace std;

/**
 * Function to print the analysis of a single word in a
 * wordcounter and then remove it
 * @param wc   an instance of WordCounter
 * @param word the word to analyze and remove
 */
void analyzeWord(WordCounter &wc, const string &word) {
    cout << word << ": " << wc.getWordCount(word) << endl;
    wc.removeWord(word);
}

/**
 * Function to print the uniqueWordCount, totalWordCount, and
 * loadFactor of a wordcounter
 * @param wc an instance of WordCounter
 */
void printStats(WordCounter &wc) {
    cout << "Word counter statistics:" << endl;
    cout << "unique: " << wc.getUniqueWordCount() << endl;
    cout << "total: " << wc.getTotalWordCount() << endl;
    cout << "load: " << std::setprecision(3) << fixed << wc.getLoadFactor();
    cout << endl;
}

/**
 * Function that process the text from a file into a wordcounter instance.
 * @param wc       an instance of WordCounter
 * @param filepath the path to the file the client wants to process
 */
void processFile(WordCounter &wc, const std::string &filepath) {
    string word, splitWord;
    ifstream inFile;
    vector<string> commonWords = English::commonWords();

    // Attempt to open file
    inFile.open(filepath);

    if (inFile.is_open()) {
        // Proceed while words are being read from file
        while (inFile >> word) {
            if (word[word.length() - 1] == '-') {
                inFile >> splitWord;
                word = word.substr(0, word.length() - 1);
                word.append(splitWord);
            }
            word = English::cleanWord(word);

            wc.addWord(word);
        }
        cout << "Before removing common words: " << endl;
        cout << "Unique Words: " << wc.getUniqueWordCount() << endl;
        cout << "Total Words : " << wc.getTotalWordCount() << endl;
        // remove common words
        for (string common: commonWords)
            wc.removeWord(common);

        printStats(wc);
    } else {
        // File name was invalid, exit application
        cout << "ERROR: cannot open file";
        return;
    }
}

/**
 * Function to prompt user for filename and capacity, process the file,
 * and prompt for word to analyze
 */
void wordCountDriver() {
    string filepath;
    int capacity;

    cout << "What is the filename: " << endl;
    cin >> filepath;
    cout << "What is the capacity: " << endl;
    cin >> capacity;

    WordCounter wc(capacity);

    processFile(wc, filepath);
    cout << endl;

    cin.ignore();
    cout << "Enter words (separated by space): " << endl;
    string word, in;
    vector<string> wordList;

    getline(cin,in);

    istringstream iss(in);
    while(iss >> word) {
        wordList.push_back(word);
    }

    cout << "Analysis of words: " << endl;
    for (string s: wordList)
        analyzeWord(wc, s);

    cout << endl;

    printStats(wc);

    cout << endl;
}

bool isPrime(int n) {
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

int getNextPrime(int n) {
    while (!isPrime(n))
        n++;

    return n;
}

int main() {
    int choice = 1;

    cout << "Welcome to word counter!" << endl << endl;

    while (choice != 0) {
        wordCountDriver();
        cout << "Enter 1 to read another file or 0 to quit" << endl;
        cin >> choice;
    }


    return 0;
}
