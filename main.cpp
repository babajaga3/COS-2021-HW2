#include <iostream>
#include <random>

#include "object.hpp"
#include "obj_store_kd.hpp"

float random_float(float range_to = 1000.f) {
    const float range_from = 0.0f;

    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_real_distribution      distribution(range_from, range_to);
    return distribution(generator);
}

Point2D random_point() {
    return { random_float(), random_float() };
}

/*
 * MADE BY:
 * TOMA BOUROV 200274715
 * HAYK MATEVOSYAN
 */
int main() {
    int number_of_enemies;

    std::cout << "How many enemies would you like to generate?\n";
    std::cin >> number_of_enemies;

    ObjStoreKD *obj_store_kd = new ObjStoreKD();
    const Object player = Object(-1, {0, 0}, {1, 1});
    std::vector<Object*> objs;

    for (int i = 0; i < number_of_enemies; i++) {
        Object enemy = Object(random_float(100000), random_point(), {0, 0});

        obj_store_kd->insert(enemy);
    }

    obj_store_kd->find_all_within_radius(player.GetLoc(), 900, objs);

    for (Object* obj : objs) {
        Point2D coords = obj->GetLoc();

        std::printf("(%f, %f)\n", coords.x, coords.y);
    }

    std::printf("\n--\t--\t--\t--\n\n");

    obj_store_kd->print();

    delete obj_store_kd;
}

/*
 * References used:
 * - https://www.geeksforgeeks.org/cpp/unordered_set-in-cpp-stl/
 * - https://www.geeksforgeeks.org/cpp/operator-overloading-cpp/
 * - https://www.geeksforgeeks.org/cpp/kd-trees-in-cpp/
 * - https://stackoverflow.com/a/20136256
 * - https://www.geeksforgeeks.org/cpp/generate-a-random-float-number-in-cpp/
 * - https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
 * - https://stackoverflow.com/questions/3784114/how-to-pass-optional-arguments-to-a-method-in-c
 */