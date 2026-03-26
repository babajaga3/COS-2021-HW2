#pragma once

#include "point.hpp"

class Node {
private:
    Point2D *point_2d;
    Node *left;
    Node *right;

public:
    // Constructors
    Node();
    Node(Point2D point_2d);

    // Getters
    Point2D* get_point_2d() const;
    Node* get_left() const;
    Node* get_right() const;

    // Setters
    void set_point_2d(Point2D &new_point_2d);
    void set_left(Node *left);
    void set_right(Node *right);
};