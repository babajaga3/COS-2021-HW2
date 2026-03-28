#pragma once

#include <random>
#include <thread>
#include <vector>

#include "obj_store_kd.hpp"
#include "object.hpp"
#include "obj_store_v.hpp"
#include "timer.hpp"

inline std::atomic<bool> loading(true);

class Benchmark {
private:
    static float random_float(const float range_to = 1000.f) {
        const float range_from = 0.0f;

        std::random_device rand_dev;
        std::mt19937 generator(rand_dev());
        std::uniform_real_distribution distribution(range_from, range_to);
        return distribution(generator);
    }

    static Point2D random_point() {
        return { random_float(), random_float() };
    }

    static void spinner() {
        const char frames[] = {'|', '/', '-', '\\'};
        int i = 0;

        while (loading) {
            std::cout << "\rGenerating enemies...   " << frames[i++ % 4] << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        std::cout << "\rDone!        \n";
    }

public:
    static double benchmark_kd_tree(int number_of_enemies = 1000) {
        ObjStoreKD *obj_store_kd = new ObjStoreKD();

        Object player = Object(-1, {0, 0}, {1, 1});
        std::vector<Object*> objs;

        std::thread t(spinner);

        for (int i = 0; i < number_of_enemies; i++) {
            Object enemy = Object(random_float(100000), random_point(), {0, 0});

            obj_store_kd->insert(enemy);
        }

        loading = false;
        t.join();

        const Timer timer;

        for (int i = 0; i < 1000; i++) {
            obj_store_kd->find_all_within_radius(player.GetLoc(), 100, objs);

            player.Update();
        }

        const double time_elapsed = timer.elapsed();
        delete obj_store_kd;

        return time_elapsed;
    }

    static double benchmark_vector(int number_of_enemies = 1000) {
        ObjStoreV *obj_store_v = new ObjStoreV();
        Object player = Object(-1, {0, 0}, {1, 1});
        std::vector<Object*> objs;

        std::thread t(spinner);

        for (int i = 0; i < number_of_enemies; i++) {
            Object enemy = Object(random_float(100000), random_point(), {0, 0});

            obj_store_v->Insert(enemy);
        }

        loading = false;
        t.join();

        const Timer timer;

        for (int i = 0; i < 1000; i++) {
            obj_store_v->FindAllWithinRadius(player.GetLoc(), 100, objs);

            player.Update();
        }

        const double time_elapsed = timer.elapsed();
        delete obj_store_v;

        return time_elapsed;
    }

    static void print_times(const std::vector<double> &times, const int num_tests, const int num_enemies, int structure = 0) {
        std::printf("|%-21s|\n", structure == 0 ? "KD_TREE" : "VECTOR");
        for (int i = 0; i < 23; i++) std::cout << "=";
        std::printf("\n|%-10s|%-10s|\n", "NUM TESTS", "NUM ENEMY");
        for (int i = 0; i < 23; i++) std::cout << "=";
        std::printf("\n|%-10i|%-10i|\n", num_tests, num_enemies);
        for (int i = 0; i < 23; i++) std::cout << "=";
        std::cout << "\n";

        for (const double time : times) {
            std::printf("%fs\n", time);
        }
    }
};