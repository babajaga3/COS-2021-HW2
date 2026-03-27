#include "obj_store_kd.hpp"

ObjStoreKD::ObjStoreKD() : root(nullptr) {}

ObjStoreKD::ObjStoreKD(Node<Object> *new_root) : root(new_root) {}

void ObjStoreKD::insert(Node<Object> *new_node, const int dim, Node<Object> *start) {
    Node<Object> *current = start;

    // if root is empty, add node as root
    if (this->root == nullptr) {
        this->root = new_node;
    }

    // if current is empty, use root as current
    if (current == nullptr) {
        current = this->root;
    }

    // if smaller, go to the left
    if (at(current, dim) < at(current, dim)) {
        // if left is empty, add node as the left node
        if (current->get_left() == nullptr) {
            current->set_left(new_node);
            return;
        }

        // if not, go to left node, start over
        insert(new_node, dim + 1, current->get_left());
    } else if (at(current, dim) >= at(current, dim)) {
        // if right is empty, add node as the right node
        if (current->get_right() == nullptr) {
            current->set_right(new_node);
            return;
        }

        // if not, go to right node, start over
        insert(new_node, dim + 1, current->get_right());
    }
}

float ObjStoreKD::at(const Node<Object> *node, const int &index) {
    const Point2D point_2d = node->get_data()->GetLoc();

    if (index % 2 == 0) {
        return point_2d.x;
    }

    return point_2d.y;
}
