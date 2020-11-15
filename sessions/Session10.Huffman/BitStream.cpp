//
// Created by Kevin Lundeen on 11/11/20.
// For Seattle University, CPSC 5005
//

#include "BitStream.h"

BitStream::BitStream(std::string s) {
    for (char c : s) {
        long n = (long) c;
        for (int i = 0; i < 8; i++) {
            append(n % 2 == 1);
            n /= 2;
        }
    }
}

bool BitStream::empty() const {
    return bits.empty();
}

void BitStream::append(bool bit) {
    bits.push_back(bit);
}

void BitStream::append(const BitStream &suffix) {
    for (const bool bit: suffix.bits)
        append(bit);
}

bool BitStream::nextBit() {
    bool bit = bits.front();
    bits.pop_front();
    return bit;
}

BitStream BitStream::cloneAndAppend(bool bit) const {
    BitStream bs;
    bs.append(*this);
    bs.append(bit);
    return bs;
}

std::string BitStream::toString() const {
    std::ostringstream sb;
    for (bool bit : bits)
        if (bit)
            sb << "1";
        else
            sb << "0";
    return sb.str();
}

int BitStream::size() const {
    return bits.size();
}
