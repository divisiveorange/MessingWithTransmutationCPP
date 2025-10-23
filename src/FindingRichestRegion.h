#pragma once
#include "Forest/Forest.h"
#include <vector>
#include <ranges>
#include <cstdlib>
#include <ostream>

#include "Forest/DataNodeHandle.h"
class RegionData {
    friend std::ostream & operator<<(std::ostream &os, const RegionData &obj) {
        return os
               << "population: " << obj.getPopulation()
               << " gdp: " << obj.getGDP()
               << " gdp per capita: " << obj.getGDPPerCapita();
    }

public:
    RegionData(const RegionData &other)
        : population(other.population),
          gdp(other.gdp) {
    }

    RegionData(RegionData &&other) noexcept
        : population(other.population),
          gdp(other.gdp) {
    }

    RegionData & operator=(const RegionData &other) {
        if (this == &other)
            return *this;
        population = other.population;
        gdp = other.gdp;
        return *this;
    }

    RegionData & operator=(RegionData &&other) noexcept {
        if (this == &other)
            return *this;
        population = other.population;
        gdp = other.gdp;
        return *this;
    }

private:
    uint64_t population;
    double gdp;
public:
    [[nodiscard]] uint64_t getPopulation() const { return population;}
    [[nodiscard]] double getGDP() const {return gdp;}
    [[nodiscard]] double getGDPPerCapita() const {return gdp / population;};
    RegionData(const uint64_t population, const double gdp) : population(population), gdp(gdp) {}

    auto operator+(const RegionData& other) const {
        return RegionData(getPopulation() + other.getPopulation(),getGDP() + other.getGDP());
    }
};
using DataHandle = Forest::DataNodeHandle<RegionData>;
using Handle = Forest::NodeHandle<RegionData>;
class FindingRichestRegion {
    Forest::Forest<RegionData> dataTree;
    std::vector<DataHandle> individuals;
    std::vector<Handle> higherGroupings;
    auto getTopView() {
        return higherGroupings | std::views::filter([](const Handle& item){return item.isTop();});
    }
public:
    DataHandle createIndividual(const double income) {
        auto handle = dataTree.createNode(RegionData(1, income));
        individuals.push_back(handle);
        return handle;
    }
    Handle constructConnection(const Handle& handle1, const Handle& handle2) {
        auto handle = dataTree.merge(handle1, handle2);
        higherGroupings.push_back(handle);
        return handle;
    }
    void lotsOfRandomOperations() {
        for (long long i = 0; i < 10000000; ++i) {
            randomCreateIndividual();
        }
        for (long long i = 0; i < 1000000; ++i) {
            randomConstructConnection();
        }
    }
    DataHandle randomCreateIndividual() {
        return createIndividual(rand() % 200000);
    }
    Handle randomConstructConnection() {
        std::array indexes = {rand() % individuals.size() + higherGroupings.size(), rand() % individuals.size() + higherGroupings.size()};
        std::vector<Handle*> handles;

        for (auto index : indexes) {
            if (index >= individuals.size()) {
                handles.push_back(&higherGroupings.at(index - individuals.size()));
            } else {
                handles.push_back(&individuals.at(index));
            }
        }
        return constructConnection(*handles.at(0), *handles.at(1));
    }
    Handle getMostPopulous() {
        auto view = getTopView();
        return *std::ranges::max_element(view, [](const Handle& item1, const Handle& item2){return item1.getSum().getPopulation() < item2.getSum().getPopulation();});
    }
    Handle getBiggestEconomy() {
        auto view = getTopView();
        return *std::ranges::max_element(view, [](const Handle& item1, const Handle& item2){return item1.getSum().getGDP() < item2.getSum().getGDP();});
    }
    Handle getRichest() {
        auto view = getTopView();
        return *std::ranges::max_element(view, [](const Handle& item1, const Handle& item2){return item1.getSum().getGDPPerCapita() < item2.getSum().getGDPPerCapita();});
    }
};