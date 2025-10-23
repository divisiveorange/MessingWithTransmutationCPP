#include <iostream>
#include "FindingRichestRegion.h"
#include "Forest/TransLonelyHolder.h"

int main() {
    {
        ArenaStack::MultiTypeArena<long long, double, std::string> arena;
        for (long long i = 0; i < 10000000; i++) {
            arena.template push<long long>(i);
        }
    }
    auto lonely1 = (new Forest::TransLonelyHolder<int>(1))->getPtr();
    auto lonely2 = (new Forest::TransLonelyHolder<int>(2))->getPtr();
    auto lonely3 = (new Forest::TransLonelyHolder<int>(3))->getPtr();
    auto ptr = static_cast<Forest::TransNormalTopHolder<int> *>(malloc(sizeof(Forest::TransNormalTopHolder<int>)));
    auto ptr2 = static_cast<Forest::TransNormalTopHolder<int> *>(malloc(sizeof(Forest::TransNormalTopHolder<int>)));
    Forest::NonBottom<int>* firstTop = lonely1->getHead()->merge(lonely2->getHead(), ptr);
    Forest::Node<int>* nodeStarFirstTop = firstTop;
    auto secondTop = firstTop->getHead()->merge(lonely3->getHead(), ptr2);

    FindingRichestRegion solver;
    srand(0);
    solver.lotsOfRandomOperations();
    std::cout << solver.getRichest().getSum() << std::endl;
    return 0;
}
