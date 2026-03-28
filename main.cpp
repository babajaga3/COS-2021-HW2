#include <iostream>
#include <vector>

#include "benchmark.hpp"
#include "timer.hpp"


/*
 * MADE BY:
 * TOMA BOUROV 200274715
 * HAYK MATEVOSYAN
 */

/*
 * TEST RESULTS:

|KD_TREE              |
=======================
|NUM TESTS |NUM ENEMY |
=======================
|3         |100000    |
=======================
0.013775s
0.004625s
0.006816s

|VECTOR               |
=======================
|NUM TESTS |NUM ENEMY |
=======================
|3         |100000    |
=======================
2.598530s
2.599969s
2.601489s

|KD_TREE              |
=======================
|NUM TESTS |NUM ENEMY |
=======================
|3         |10000     |
=======================
0.000477s
0.000791s
0.002419s

|VECTOR               |
=======================
|NUM TESTS |NUM ENEMY |
=======================
|3         |10000     |
=======================
0.259912s
0.259741s
0.261913s

|KD_TREE              |
=======================
|NUM TESTS |NUM ENEMY |
=======================
|3         |1000      |
=======================
0.000707s
0.000523s
0.000321s

|VECTOR               |
=======================
|NUM TESTS |NUM ENEMY |
=======================
|3         |1000      |
=======================
0.026860s
0.023836s
0.023884s

* PRELIMINARY CONCLUSION:
*   On the condition that everything in the code works correctly (very doubtful about that),
*   what can be seen is that the KD tree consistently outperforms the vector in all tests,
*   regardless of number of enemies. We even ran a 1M enemies test just to compare the speeds and the KD tree
*   is the more optimal choice by a big margin:

|KD_TREE              |
=======================
|NUM TESTS |NUM ENEMY |
=======================
|3         |1000000   |
=======================
0.127299s
0.069705s
0.074712s

|VECTOR               |
=======================
|NUM TESTS |NUM ENEMY |
=======================
|3         |1000000   |
=======================
27.186594s
27.175901s
26.195602s


* ACKNOWLEDGEMENTS:
*   The code is mostly following the requirements of the assignment, except for keeping track of the
*   "insertion of two objects with duplicate keys" - both me and Hayk did not manage to figure out what that means :P
*   By the time we got to that part, it was a bit too late to ask.
 */
int main() {
    int number_of_enemies;
    int number_of_tests;

    std::vector<double> kd_tree_times;
    std::vector<double> vector_times;

    std::cout << "How many enemies would you like to generate?\n";
    std::cin >> number_of_enemies;

    std::cout << "How many tests would you like to run?\n";
    std::cin >> number_of_tests;

    for (int i = 0; i < number_of_tests; i++) {
        const double time = Benchmark::benchmark_kd_tree(number_of_enemies);

        kd_tree_times.push_back(time);
    }

    for (int i = 0; i < number_of_tests; i++) {
        const double time = Benchmark::benchmark_vector(number_of_enemies);

        vector_times.push_back(time);
    }

    Benchmark::print_times(kd_tree_times, number_of_tests, number_of_enemies);
    Benchmark::print_times(vector_times, number_of_tests, number_of_enemies, 1);
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
 * - https://www.learncpp.com/cpp-tutorial/timing-your-code/
 * - https://www.geeksforgeeks.org/cpp/using-keyword-in-cpp-stl/
 */