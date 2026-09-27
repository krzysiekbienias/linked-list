#include <iostream>
#include "../header/api.hpp"
#include "../unit_tests/test_utils.hpp"

int main() {
    LinkedList ll;
    buildList(ll, {4, 5, 8});
    std::cout << ll << std::endl;
}
