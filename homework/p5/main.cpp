#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include "WordCounter.h"
#include "English.h"

using namespace std;

void processFile(const std::string &filepath) {
    string word, splitWord;
    ifstream inFile;

    // Attempt to open file
    inFile.open(filepath.c_str());

    if (inFile.is_open()) {
        // Proceed while lines are being read from file
        while (inFile >> word) {
            if (word[word.length() - 1] == '-') {
                inFile >> splitWord;
                word = word.substr(0, word.length() - 1);
                word = word + splitWord;
            }
            word = English::cleanWord(word);
            cout << word << endl;
        }
    } else {
        // File name was invalid, exit application
        cout << "ERROR: cannot open file";
        return;
    }
}

int main() {
    WordCounter wc;

    cout << "Apple 1: " << wc.addWord("apple") << endl;
    cout << "Apple 2: " << wc.addWord("apple") << endl;
    cout << "Apple 3: " << wc.addWord("apple") << endl;
    cout << "Pear 1 : " << wc.addWord("pear") << endl;
    cout << "Pear 2 : " << wc.addWord("pear") << endl;
    cout << "Table 1: " << wc.addWord("table") << endl;

    cout << endl;

    cout << "Unique words s/b 3: " << wc.getUniqueWordCount() << endl;
    cout << "Total words s/b 6 : " << wc.getTotalWordCount() << endl;
    cout << "Load Factor       : " << std::setprecision(3) << fixed << wc.getLoadFactor() << endl;

    cout << endl;
    cout << "Remove apple" << endl;
    wc.removeWord("apple");

    cout << "Unique words s/b 2: " << wc.getUniqueWordCount() << endl;
    cout << "Total words s/b 3 : " << wc.getTotalWordCount() << endl;
    cout << "Load Factor       : " << std::setprecision(3) << fixed << wc.getLoadFactor() << endl;

    cout << endl;

    cout << "Test empty" << endl;
    cout << "Not empty: " << (wc.empty() ? "false" : "true") << endl;
    wc.removeWord("pear");
    wc.removeWord("table");
    cout << "Empty    : " << (wc.empty() ? "true" : "false") << endl;
    cout << endl;

    processFile("../files/alice.txt");

    return 0;
}
