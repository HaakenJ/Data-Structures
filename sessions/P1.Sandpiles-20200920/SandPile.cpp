//
// Created by Kevin Lundeen on 9/7/20
// for Seattle University, CPSC 5005, Fall 2020
//

#include <sstream>
#include "SandPile.h"

using namespace std;

SandPile::SandPile() {
    pile = new int[ARRAY_SIZE];
    int args[] = {2, 1, 2, 1, 0, 1, 2, 1, 2}; // zero element
    setPile(args);
}

SandPile::SandPile(const int *cells) : SandPile() {
    setPile(cells);
}

SandPile::SandPile(const SandPile &other) {
    pile = new int[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
        this->pile[i] = other.pile[i];
}

SandPile &SandPile::operator=(const SandPile &other) {
    if (this != &other) { // check that we are not assigning to self
        // in this case we don't need to delete and reallocate pile -- we can just overwrite it
        for (int i = 0; i < ARRAY_SIZE; i++)
            pile[i] = other.pile[i];
    }
    return *this; // always return ourself from operator=
}

SandPile::~SandPile() {
    delete[] pile;
}

void SandPile::setPile(const int *cells) {
    // check first that they all are non-negative
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (cells[i] < 0) {
            // rather than set to bad values, set everything to 0
            int args[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            setPile(args);
            return;  // we handled the error by setting to 0's, so we're done
        }
    }

    // normal case
    for (int i = 0; i < ARRAY_SIZE; i++)
        pile[i] = cells[i];
}

string SandPile::toString() const {
    ostringstream buffer;
    for (int row = 0; row < DIM; row++) {
        buffer << pile[index(row, 0)] << " " << pile[index(row, 1)] << " " << pile[index(row, 2)]
               << (row == DIM - 1 ? "" : " / ");
    }
    return buffer.str();
}

bool SandPile::isStable() const {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (pile[i] > MAX_STABLE)
            return false;
    }
    return true;
}

void SandPile::stabilize() {
    while (!isStable()) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (pile[i] > MAX_STABLE) {
                int row = i / DIM;
                int col = i % DIM;
                pile[i] -= MAX_STABLE + 1;
                if (row > 0)
                    pile[index(row - 1, col)] += 1;
                if (row + 1 < DIM)
                    pile[index(row + 1, col)] += 1;
                if (col > 0)
                    pile[index(row, col - 1)] += 1;
                if (col + 1 < DIM)
                    pile[index(row, col + 1)] += 1;
            }
        }
    }
}

void SandPile::addPile(const SandPile &other) {
    for (int i = 0; i < ARRAY_SIZE; i++)
        pile[i] += other.pile[i];
    stabilize();
}

bool SandPile::isInGroup() const {
    SandPile sum;
    sum.addPile(*this);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (pile[i] != sum.pile[i])
            return false;
    }
    return true;
}

int SandPile::index(int row, int col) {
    return row * DIM + col;
}
