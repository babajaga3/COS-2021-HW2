#pragma once

template<typename T>
class Node {
private:
    T data;
    Node *left;
    Node *right;

public:
    Node(T data) : data(data), left(nullptr), right(nullptr) {}

    // Getters
    Node<T>* get_left() const {
        return left;
    }

    Node<T>* get_right() const {
        return right;
    }

    T& get_data() {
        return data;
    }

    // Setters
    void set_left(Node *left) {
        this->left = left;
    }

    void set_right(Node *right) {
        this->right = right;
    }

    void set_data(T &new_data) {
        this->data = new_data;
    }
};