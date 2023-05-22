// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint64_t i = 1; i <= n; i++)
        result *= i;
    return result;
}

std::vector<char> getPerm(const Tree& tree, int n) {
    if (tree.getSize() == 0 || n > fact(tree.getSize()))
        return {};
    n--;
    const Tree* ptr = &tree;
    std::vector<char> result;
    for (int i = 0; i < tree.getSize(); i++) {
        int temp = fact(ptr->getSize()-1);
        ptr = ptr->getChild(n / temp);
        result.push_back(ptr->getValue());
        n%=temp;
    }
    return result;
}
