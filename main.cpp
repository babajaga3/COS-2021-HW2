#include <iostream>

#include "object.hpp"
#include "obj_store_kd.hpp"

int main() {

    const Object obj1 = Object(1, {1, 2}, {3, 4});

    auto *obj_store = new ObjStoreKD();

    obj_store->insert_main(obj1);

    obj_store->print_main();
}

/*
 * References used:
 * - https://www.geeksforgeeks.org/cpp/unordered_set-in-cpp-stl/
 * - https://www.geeksforgeeks.org/cpp/operator-overloading-cpp/
 */