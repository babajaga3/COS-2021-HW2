#pragma once

#include <unordered_set>

#include "node.hpp"
#include "object.hpp"

class ObjStoreKD {
private:
    Node<Object> *root;
    std::unordered_set<int> *existing_keys;

    void kd_insert(Node<Object> *new_node, int dim, Node<Object> *start);
    void kd_print(Node<Object> *node, int dim, bool left) const;

    static float at(Node<Object> *node, const int &index);
    static void cleanup_tree(const Node<Object> *node);
    static void kd_find_all(Point2D center, float radius, std::vector<Object *> &objs, Node<Object> *node);

public:
    ObjStoreKD();
    ObjStoreKD(Node<Object> *new_root);
    ~ObjStoreKD();

    bool insert(const Object &obj);
    void find_all_within_radius(Point2D center, float radius, std::vector<Object*> &objs) const;
    void print() const;

};
