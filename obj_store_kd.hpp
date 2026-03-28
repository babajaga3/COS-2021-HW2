#pragma once

#include <unordered_set>

#include "node.hpp"
#include "object.hpp"

class ObjStoreKD {
private:
    Node<Object> *root;
    std::unordered_set<int> *existing_ids;

public:
    ObjStoreKD();
    ObjStoreKD(Node<Object> *new_root);

    void insert(Node<Object> *new_node, int dim, Node<Object> *start);
    bool insert_main(Object obj);
    static void print(Node<Object> *node, int dim);
    static float at(Node<Object> *node, const int &index);
    void print_main() const;
};
