//
// Created by Kevin Lundeen on 9/7/20
// for Seattle University, CPSC 5005, Fall 2020
//

#include <iostream>
#include "SandPile.h"

using namespace std;

/**
 * Tests the stabilize method and prints out results.
 * @param title prints this as a title of the test
 * @param args  initial elements of the sandpile
 */
void testStabilize(string title, const int *args) {
    SandPile test(args);
    cout << title << " before stabilization: " << test.toString();
    test.stabilize();
    cout << " after: " << test.toString() << endl;
}

/**
 * Tests the addPile method and prints out results.
 * @param title prints this as a title of the test
 * @param argsa elements of the first addend sandpile
 * @param argsb elements of the second addend sandpile
 */
void testAdd(string title, const int *argsa, const int *argsb) {
    SandPile a(argsa), b(argsb);
    cout << title << " a: " << a.toString() << "   b: " << b.toString();
    a.addPile(b);
    cout << "   a + b: " << a.toString() << endl;
}

// Forward declarations for the two versions of countGroup:
void countGroupRec(int *args, int remaining, int &inGroup, int &inTotal);
void countGroupIt(int &inGruop, int &inTotal);

/**
 * Counts the number of sandpiles in the group and prints out a report.
 * Looks at each possible 3x3 sandpile and calls isInGroup for each.
 */
void countGroup() {
    // Try the iterative solution:
    int inGroup = 0, count = 0;
    countGroupIt(inGroup, count);
    cout << "sand piles in group: " << inGroup << endl;
    cout << "out of total 3x3 sand piles: " << count << endl;

    // And more generally, use recursion (note how we could have higher dimensions here easily
    int args[SandPile::DIM * SandPile::DIM];
    inGroup = count = 0;
    countGroupRec(args, 9, inGroup, count);
    cout << "sand piles in group: " << inGroup << endl;
    cout << "out of total 3x3 sand piles: " << count << endl;
}

/**
 * Recursive helper for counting sandpiles in the abelian group.
 * @param inGroup   returns number of SandPiles found in the group
 * @param inTotal   returns total number of SandPiles checked
 */
void countGroupIt(int &inGroup, int &inTotal) {
    for (int i1 = 0; i1 <= SandPile::MAX_STABLE; i1++) {
        for (int i2 = 0; i2 <= SandPile::MAX_STABLE; i2++)
            for (int i3 = 0; i3 <= SandPile::MAX_STABLE; i3++)
                for (int i4 = 0; i4 <= SandPile::MAX_STABLE; i4++)
                    for (int i5 = 0; i5 <= SandPile::MAX_STABLE; i5++)
                        for (int i6 = 0; i6 <= SandPile::MAX_STABLE; i6++)
                            for (int i7 = 0; i7 <= SandPile::MAX_STABLE; i7++)
                                for (int i8 = 0; i8 <= SandPile::MAX_STABLE; i8++)
                                    for (int i9 = 0; i9 <= SandPile::MAX_STABLE; i9++) {
                                        int args[] = {i1, i2, i3, i4, i5, i6, i7, i8, i9};
                                        SandPile pile(args);
                                        if (pile.isInGroup())
                                            inGroup++;
                                        inTotal++;
                                    }
    }
}

/**
 * Recursive helper for counting sandpiles in the abelian group.
 * @param args      DIM*DIM-element array to construct a SandPile
 * @param remaining number of elements not yet set in args
 * @param inGroup   accumulates additional SandPiles found in the group (pass by reference)
 * @param inTotal   accumulates total number of SandPiles checked (pass by reference)
 */
void countGroupRec(int *args, int remaining, int &inGroup, int &inTotal) {
    if (remaining == 0) {
        // base case: args all filled in, so test it
        SandPile pile(args);
        if (pile.isInGroup())
            inGroup++;
        inTotal++;
    } else {
        // recursive case, fill in the next position with 0, 1, 2, 3, and recurse on each
        for (int i = 0; i <= SandPile::MAX_STABLE; i++) {
            args[remaining - 1] = i;
            countGroupRec(args, remaining - 1, inGroup, inTotal);
        }
    }
}

/**
 * Main entry point of tests.
 * @return 1
 */
int main() {
    // Test that a zero-arg ctor is the zero sand pile per Dr. Garcia-Puente
    SandPile zero;
    cout << "zero (using no-arg ctor):" << zero.toString() << endl;
    cout << endl;

    // Test stabilize
    int stab1[] = {0, 0, 0, 0, 4, 0, 0, 0, 0};
    testStabilize("test1", stab1);

    int stab2[] = {4, 0, 0, 0, 4, 0, 0, 0, 0};
    testStabilize("test2", stab2);

    int stab3[] = {4, 0, 0, 0, 10, 0, 0, 0, 0};
    testStabilize("test3", stab3);

    int stab4[] = {4, 4, 0, 0, 10, 0, 0, 0, 0};
    testStabilize("test4", stab4);

    int stab5[] = {4, 4, 4, 10, 10, 0, 22, 1, 5};
    testStabilize("test5", stab5);

    cout << endl;

    // Test addPile
    int a1[] = {0, 0, 0, 0, 2, 0, 0, 0, 0};
    int b1[] = {0, 0, 0, 0, 2, 0, 0, 0, 0};
    testAdd("add1", a1, b1);

    int a2[] = {1, 2, 0, 2, 1, 1, 0, 1, 3};
    int b2[] = {2, 1, 3, 1, 0, 1, 0, 1, 0};
    testAdd("add2", a2, b2);

    int a3[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    int b3[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    testAdd("add3", a3, b3);

    cout << endl;

    // Test add to zero
    SandPile all3s(a3);
    all3s.addPile(zero);
    cout << "all 3's + zero: " << all3s.toString() << " (the same => in group)" << endl;
    for (int i = 0; i < 9; i++)
        a3[i] = 2;
    SandPile all2s(a3);
    all2s.addPile(zero);
    cout << "all 2's + zero: " << all2s.toString() << " (the same => in group)" << endl;

    // Test isInGroup
    int g1args[] = {3, 2, 2, 2, 1, 1, 3, 3, 3};
    SandPile g1(g1args);
    cout << "isInGroup test1 " << g1.toString() << (g1.isInGroup() ? " IS" : " is NOT") << " in group (expect yes)"
         << endl;
    int g2args[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    SandPile g2(g2args);
    cout << "isInGroup test2 " << g2.toString() << (g2.isInGroup() ? " IS" : " is NOT") << " in group (expect not)"
         << endl;
    cout << endl;

    // Count the number (and ratio) of sand piles in the abelian group
    countGroup();

    return 0;
}
