#include <iostream>
#include "ArenaStack/Arena.h"
#include "ArenaStack/TransIncreasableAlone.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ArenaStack::TransIncreasableAlone<int> var;
    auto& var2 = *var;
    return 0;
}