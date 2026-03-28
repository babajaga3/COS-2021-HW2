#include "obj_store_v.hpp"

ObjStoreV::ObjStoreV() {
    this->objs = {};
}

ObjStoreV::ObjStoreV(std::vector<Object*> & objs) {
    this->objs = objs;
}

bool ObjStoreV::Insert(Object* o) {
    for (Object* obj : objs) {
        if (obj->GetID() == o->GetID()) {
            return false;
        }
    }
    this->objs.push_back(o);
    return true;
}

void ObjStoreV::FindAllWithinRadius(Point2D center, float radius, std::vector<Object*> & objects) {
    for (Object* obj : this->objs) {
        if (obj->IsWithinCircle(center, radius)==true) {
            objects.push_back(obj);
        }
    }
}
