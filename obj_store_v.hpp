#include <unordered_set>
#include <vector>

#include "object.hpp"

class ObjStoreV {
private:
    std::vector<Object*> objs;

public:
    ObjStoreV();
    ObjStoreV(std::vector<Object*> & objs);

    bool Insert(Object* o);
    void FindAllWithinRadius(Point2D center, float radius, std::vector<Object*> & objs);

};