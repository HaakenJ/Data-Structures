#include <iostream>
#include "IntHashSet.h"
using namespace std;


int hashString(string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++)
        hash += key[i]; // key[i] is the "character" at i, which is a char
        // (ascii value of the letter, e.g. 'A' 65)
    return hash;
}

int main() {
    IntHashSet set;

    if (!set.empty())
        cout << "FAILED empty when empty" << endl;

    int tests[] = {0, 4, 88, 6, 17};
    for (int test: tests)
        set.add(test);

    if (set.empty())
        cout << "FAILED empty when not" << endl;

    for (int test: tests)
        if (!set.has(test))
            cout << "FAILED has when had " << test << endl;
    for (int test: tests)
        if (set.has(test + 1))
            cout << "FAILED has when hadn't " << test << endl;

    cout << "done testing" << endl;
    return EXIT_SUCCESS;
}
