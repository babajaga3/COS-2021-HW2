#pragma once

template<typename T>
class Node {
private:
    T *data;
    Node *left;
    Node *right;

public:
    // Constructors
    Node(T data);

    // Getters
    T* get_data() const;
    Node* get_left() const;
    Node* get_right() const;

    // Setters
    void set_data(T &new_data);
    void set_left(Node *left);
    void set_right(Node *right);
};