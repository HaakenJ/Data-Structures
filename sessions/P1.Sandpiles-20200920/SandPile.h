//
// Created by Kevin Lundeen on 9/7/20
// for Seattle University, CPSC 5005, Fall 2020
//

#pragma once

#include <iostream>

/**
 * SandPile class implements a 3x3 sand pile in the abelian sandpile model.
 * @see https://www.youtube.com/watch?v=1MtEUErz7Gg
 * @see https://en.wikipedia.org/wiki/Abelian_sandpile_model
 * @see Seattle University, CPSC 5005, Fall 2020, P1 project
 * This is different from L1 implementation in that the internal
 * array, pile, is a dynamic array (in anticipation of the next
 * version where we would have arbitrary dimensions). We've also
 * added the addPile and isInGroup methods, as well as two ctors
 * and the associated big 4 (since pile is a dynamic array).
 */
class SandPile {
public:
    static const int DIM = 3;         // Hence 3x3 sand piles
    static const int MAX_STABLE = 3;  // Topples on 4 or more

    /**
     * Zero-argument constructor constructs a "zero" sand pile.
     */
    SandPile();

    /**
     * Constructs a 3x3 sand pile with the elements
     * @param cells 1st row elements, then 2nd, etc., all in one flat array
     */
    SandPile(const int *cells);

    /**
     * Copy constructor.
     * @param other
     */
    SandPile(const SandPile &other);

    /**
     * Assignment operator.
     * @param other
     * @return
     */
    SandPile &operator=(const SandPile &other);

    /**
     * Destructor
     */
    ~SandPile();

    /**
     * Set the values of each cell in this sand pile.
     * @param cells 1st row elements, then 2nd, etc., all in one flat array
     */
    void setPile(const int *cells);

    /**
     * Get a string suitable for printing out.
     * @return a 3-line string with the contents of this sand pile
     */
    std::string toString() const;

    /**
     * Is this sand pile stable or will it topple?
     * I.e., if there are any cells over 3 (SandPile::MAX_STABLE) then it will topple.
     *
     * @return true if it won't topple, false if it will
     */
    bool isStable() const;

    /**
     * Topple this sand pile until it is stable (according to toppling rules).
     * Each unstable cell spills one grain of sand in each direction. If they fall
     * off the edge that's ok.
     */
    void stabilize();

    /**
     * Add in the cells of another sand pile into this one.
     * this = this + other
     * @param other addend sand pile
     */
    void addPile(const SandPile &other);

    /**
     * Check if this sand pile is in the abelian group explained by Dr. Garcia-Puente
     * @return true if it is the group (i.e., this + zero == this), false otherwise
     */
    bool isInGroup() const;

private:
    static const int ARRAY_SIZE = DIM * DIM;  // size of flat array

    static int index(int row, int col);  // helper to map from r,c --> index into flat array

    int *pile;  // flat array
};
