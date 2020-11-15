#include <iostream>
#include "WordCounter.h"

using namespace std;

int main() {
    WordCounter wc;

    cout << wc.addWord("apple") << endl;
    cout << wc.addWord("apple") << endl;
    cout << wc.addWord("apple") << endl;
    cout << wc.addWord("pear") << endl;
    cout << wc.addWord("pear") << endl;
    cout << wc.addWord("table") << endl;

    return 0;
}
