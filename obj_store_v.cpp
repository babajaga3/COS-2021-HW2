#include "obj_store_v.hpp"

ObjStoreV::ObjStoreV() {

}

ObjStoreV::ObjStoreV(std::vector<Object> objs) {
    this->objs = objs;
}

bool ObjStoreV::Insert(Object o) {
    for (Object obj : objs) {
        if (obj.GetID() == o.GetID()) {
            return false;
        }
    }
    this->objs.push_back(o);
    return true;
}