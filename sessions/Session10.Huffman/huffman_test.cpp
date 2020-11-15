//
// Created by Kevin Lundeen on 11/11/20.
// For Seattle University, CPSC 5005
//

#include <iostream>
#include "Huffman.h"
#include "BitStream.h"
using namespace std;

int main() {
    string test = "vivien's vexing vine.";
    // test = "asd;lkfja;sldkjf ;alsdkfj ;asldkfjaaaaaaaaaaaaaaaaaaaaaaa; "
    //        "lsdkfja;sdlfkja ds;fklj aaaaaaaaaads;flkjadsf;lasdkjf ;asldkjf "
    //        "a;sdlkfja;sdlkfajsd;flkasdjf ;asf ";

    Huffman huffy(test, true);
    BitStream *bs = huffy.encode(test);

    int uncompressedBytes = test.length();
    int compressedBytes = bs->size() / 8;
    double compressionRatioPct = 100.0 *
            (1.0 - (double)compressedBytes / uncompressedBytes);

    cout << "test: \"" << test << "\"" << endl;
    cout << "uncompressed: " << uncompressedBytes << " bytes" << endl;
    cout << "uncompressed bitstream: " << BitStream(test).toString() << endl;
    cout << "compressed: "<< compressedBytes << " bytes (compression: "
            << (int) compressionRatioPct << "%)" << endl;
    cout << "compressed bitstream: " << bs->toString() << endl;

    string test2 = huffy.decode(bs);
    if (test == test2)
        cout << "successfully decoded to same string" << endl;
    else
        cout << "FAIL" << endl;

    delete bs;
    return EXIT_SUCCESS;
}
