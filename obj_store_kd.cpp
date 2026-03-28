#include "obj_store_kd.hpp"

#include <iostream>

ObjStoreKD::ObjStoreKD() : root(nullptr) {
    this->existing_ids = new std::unordered_set<int>();
}

ObjStoreKD::ObjStoreKD(Node<Object> *new_root) : root(new_root) {
    this->existing_ids = new std::unordered_set<int>();
}

ObjStoreKD::~ObjStoreKD() {
    cleanup_tree(root);
}

void ObjStoreKD::cleanup_tree(const Node<Object> *node) {
    if (node == nullptr) return;
    cleanup_tree(node->get_left());
    cleanup_tree(node->get_right());
    delete node;
}

void ObjStoreKD::kd_insert(Node<Object> *new_node, const int dim, Node<Object> *start) {
    Node<Object> *current = start;

    // if root is empty, add node as root
    if (this->root == nullptr) {
        this->root = new_node;
        return;
    }

    // if current is empty, use root as current
    if (current == nullptr) {
        current = this->root;
    }

    if (new_node == nullptr) {
        return;
    }

    // if smaller, go to the left
    if (at(new_node, dim) < at(current, dim)) {
        // if left is empty, add node as the left node
        if (current->get_left() == nullptr) {
            current->set_left(new_node);
            return;
        }

        // if not, go to left node, start over
        this->kd_insert(new_node, dim + 1, current->get_left());
    } else if (at(new_node, dim) >= at(current, dim)) {
        // if right is empty, add node as the right node
        if (current->get_right() == nullptr) {
            current->set_right(new_node);
            return;
        }

        // if not, go to right node, start over
        this->kd_insert(new_node, dim + 1, current->get_right());
    }
}

bool ObjStoreKD::insert(const Object &obj) {

    // verify that the id doesn't already exist
    if (existing_ids->contains(obj.GetID())) {
        return false;
    }

    // add id to set
    existing_ids->insert(obj.GetID());

    Node<Object> *new_node = new Node<Object>(obj);

    this->kd_insert(new_node, 0, nullptr);

    return true;
}

void ObjStoreKD::print() const {
    kd_print(root, 0);
}

void ObjStoreKD::kd_print(Node<Object>* node, int dim) {
    // Base case: If node is null, return
    if (node == nullptr) return;

    // Print current node with indentation based on dim
    for (int i = 0; i < dim; i++) std::cout << "  ";
    std::cout << "(";
    for (int i = 0; i < 2; i++) {
        std::cout << at(node, i);
        if (i < 2 - 1) std::cout << ", ";
    }
    std::cout << ")" << std::endl;

    // Recursively print left and right children
    kd_print(node->get_left(), dim + 1);
    kd_print(node->get_right(), dim + 1);
}

float ObjStoreKD::at(Node<Object> *node, const int &index) {
    if (node == nullptr) {
        throw std::runtime_error("ObjStoreKD::at - Passed node is null.");
    }

    const Point2D point_2d = node->get_data().GetLoc();

    if (index % 2 == 0) {
        return point_2d.x;
    }

    return point_2d.y;
}
