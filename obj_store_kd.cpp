#include "obj_store_kd.hpp"

// Constructors
ObjStoreKD::ObjStoreKD() {
    this->root = nullptr;
}

ObjStoreKD::ObjStoreKD(Node<Object> *new_root) {
    this->root = new_root;
}

// required functions
bool ObjStoreKD::insert(Object obj) {

}

void ObjStoreKD::find_all_within_radius(Point2D point_2d, float radius, std::vector<Object *> &objs) const {

}
