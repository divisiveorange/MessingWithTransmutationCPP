#include <iostream>
#include "ArenaStack/Arena.h"
#include "ArenaStack/TransIncreasableAlone.h"
#include "ArenaStack/ArenaMultiType.h"
#include <cassert>
#include <vector>
#include <string>
#include "Forest/TransLonely.h"
#include "Forest/TransNormalTop.h"
#include "FindingRichestRegion.h"

int main() {
    ArenaStack::TransIncreasableAlone<int> var;
    auto& var2 = *var;
    ArenaStack::MultiTypeArena<int, std::string, double, std::vector<char>> multiTypeArena;
    multiTypeArena.push<int>(56);
    auto intStar1 = multiTypeArena.push<int>(5);
    auto intStar2 = multiTypeArena.push<int>(4);
    assert(intStar1 + 1 == intStar2);
    multiTypeArena.pop<int>();
    auto intStar3 = multiTypeArena.push<int>(3);
    assert(intStar2 == intStar3);
    auto str = multiTypeArena.push<std::string>("hi");
    ArenaStack::MultiTypeArena<Forest::TransLonely<int>, Forest::TransNormalTop<int>> forest;
    Forest::TransLonely<int> town1(1);
    Forest::TransLonely<int> town2(2);
    auto town3 = town1->getHead()->merge(town2->getHead(), forest.pushRaw<Forest::TransNormalTop<int>>());
    FindingRichestRegion solver;
    solver.createIndividual(50000);

    return 0;
}