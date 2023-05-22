// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>

class Tree {
 private:
    char value;
    std::vector <Tree*> childs;
    explicit Tree(char x) : value(x) {}
    void add(Tree* root, std::vector<char> vect) {
        for (int i = 0; i < vect.size(); i++) {
            Tree* child = new Tree(vect[i]);
            childs.push_back(child);
            std::vector<char> tmp = vect;
            tmp.erase(tmp.begin() + i);
            child->add(child, tmp);
        }
    }

 public:
    explicit Tree(std::vector<char> value) {
        Tree* root = new Tree('r');
        add(root, value);
    }
    char getValue() const {
        return value;
    }
    int getSize() const {
        return childs.size();
    }
    Tree* getChild(int n) const {
        return childs[n];
    }
};
#endif  // INCLUDE_TREE_H_
