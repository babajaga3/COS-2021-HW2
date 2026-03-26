#include "node.hpp"
#include "point.hpp"

// Initializers
Node::Node() : left(nullptr), right(nullptr) {
    this->point_2d = new Point2D();
}
Node::Node(const Point2D point_2d) : left(nullptr), right(nullptr) {
    this->point_2d = new Point2D(point_2d.x, point_2d.y);
}

// Getters
Point2D* Node::get_point_2d() const {
    return point_2d;
}
Node* Node::get_left() const {
    return left;
}
Node* Node::get_right() const {
    return right;
}

// Setters
void Node::set_point_2d(Point2D &new_point_2d) {
    this->point_2d = &new_point_2d;
}
void Node::set_left(Node *left) {
    this->left = left;
}
void Node::set_right(Node *right) {
    this->right = right;
}

