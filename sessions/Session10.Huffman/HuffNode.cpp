//
// Created by Kevin Lundeen on 11/11/20.
// For Seattle University, CPSC 5005
//

#include <sstream>
#include "HuffNode.h"

using namespace std;

HuffNode::HuffNode(int c, int freq) {
    left = nullptr;
    right = nullptr;
    value = (char) c;
    frequency = freq;
}

HuffNode::HuffNode(HuffNode *left, HuffNode *right) {
    this->left = left;
    this->right = right;
    value = 0; // ignored
    frequency = left->frequency + right->frequency;
}

string HuffNode::toString() const {
    ostringstream out;
    out << "freq(" << frequency << "): ";
    toStringR(this, "", out);
    return out.str();
}

void HuffNode::toStringR(const HuffNode *curr, string pre, ostringstream &out) {
    if (curr != nullptr) {
        if (curr->isLeaf()) {
            out << pre << ":(" << curr->value << "," << curr->frequency << ") ";
        } else {
            toStringR(curr->left, pre + "0", out);
            toStringR(curr->right, pre + "1", out);
        }
    }
}

bool HuffNode::isLeaf() const {
    // would actually be sufficient to just check either child since we never
    // have just one child
    return left == nullptr && right == nullptr;
}

void HuffNode::clear(HuffNode *root) {
    if (root != nullptr) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}
