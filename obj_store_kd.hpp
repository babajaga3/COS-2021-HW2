#pragma once

#include "node.hpp"
#include "object.hpp"

class ObjStoreKD {
private:
    Node<Object> *root;

public:
    ObjStoreKD();
    ObjStoreKD(Node<Object> *new_root);

    void insert(Node<Object> *new_node, int dim, Node<Object> *start);
    static float at(const Node<Object> *node, const int &index);
};
