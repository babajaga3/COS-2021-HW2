#include "node.hpp"

template<typename T>
Node<T>::Node(T data) : data(data), left(nullptr), right(nullptr) {}

// Getters
template<typename T>
Node<T> *Node<T>::get_left() const {
    return left;
}

template<typename T>
Node<T> *Node<T>::get_right() const {
    return right;
}

template<typename T>
T *Node<T>::get_data() const {
    return data;
}

// Setters
template<typename T>
void Node<T>::set_left(Node *left) {
    this->left = left;
}

template<typename T>
void Node<T>::set_right(Node *right) {
    this->right = right;
}

template<typename T>
void Node<T>::set_data(T &new_data) {
    this->data = new_data;
}
