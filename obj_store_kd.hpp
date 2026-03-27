#pragma once
#include <vector>

#include "node.hpp"
#include "object.hpp"

class ObjStoreKD {
private:
    Node<Object> *root;

public:
    ObjStoreKD();
    ObjStoreKD(Node<Object> *new_root);

    bool insert(Object obj);
    void find_all_within_radius(Point2D point_2d, float radius, std::vector<Object*> &objs) const;
};
