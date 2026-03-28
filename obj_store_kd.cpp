#include "obj_store_kd.hpp"

#include <iostream>

ObjStoreKD::ObjStoreKD() : root(nullptr) {
    this->existing_keys = new std::unordered_set<int>();
}

ObjStoreKD::ObjStoreKD(Node<Object> *new_root) : root(new_root) {
    this->existing_keys = new std::unordered_set<int>();
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
    if (existing_keys->contains(obj.GetID())) {
        return false;
    }

    // add id to set
    existing_keys->insert(obj.GetID());

    Node<Object> *new_node = new Node<Object>(obj);

    this->kd_insert(new_node, 0, nullptr);

    return true;
}

void ObjStoreKD::kd_print(Node<Object>* node, int dim, bool left) const {
    if (node == nullptr) return;

    for (int i = 0; i < dim; i++) std::cout << "  ";

    if (node == root) {
        std::printf("%s (", "[ROOT]");
    } else if (left) {
        std::printf("%s (", "[L]");
    } else {
        std::printf("%s (", "[R]");
    }

    for (int i = 0; i < 2; i++) {
        if (dim % 2 == 0) {
            std::printf("\x1B[32m%f\033[0m", at(node, i));
        } else {
            std::printf("\x1B[36m%f\033[0m", at(node, i));
        }


        if (i < 1) std::cout << ", ";
    }
    std::printf(") %s\n", dim % 2 == 0 ? "[x]" : "[y]");

    kd_print(node->get_left(), dim + 1, true);
    kd_print(node->get_right(), dim + 1, false);
}

void ObjStoreKD::print() const {
    kd_print(root, 0, false);
}

void ObjStoreKD::kd_find_all(Point2D center, float radius, std::vector<Object *> &objs, Node<Object> *node) {
    if (node == nullptr) return;

    Object *current = &node->get_data();

    if (current->IsWithinCircle(center, radius)) {
        objs.push_back(current);

    }

    kd_find_all(center, radius, objs, node->get_left());
    kd_find_all(center, radius, objs, node->get_right());
}

void ObjStoreKD::find_all_within_radius(Point2D center, float radius, std::vector<Object *> &objs) const {
    kd_find_all(center, radius, objs, this->root);
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
