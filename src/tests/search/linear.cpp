#include <catch2/catch_test_macros.hpp>

#include <ranges>

#include "search/linear.h"

using namespace algorithms::search::linear;

TEST_CASE("can find item using linear search basic", "[algorithm][search][linear]") {
    std::vector<std::uint32_t> set {};

    for (auto i {0u}; i < 10000; ++i) {
        set.push_back(i);
    }

    REQUIRE(linear_basic<std::uint32_t>(set, 0));
    REQUIRE(linear_basic<std::uint32_t>(set, 5000));
    REQUIRE(linear_basic<std::uint32_t>(set, 9999));
    REQUIRE_FALSE(linear_basic<std::uint32_t>(set, 10000));
}

TEST_CASE("can find item using linear search sentinel", "[algorithm][search][linear]") {
    std::vector<std::uint32_t> set {};

    for (auto i {0u}; i < 10000; ++i) {
        set.push_back(i);
    }

    // we need to use sections because `set` will be modified
    SECTION("find 0") {
        REQUIRE(linear_sentinel<std::uint32_t>(set, 0));
    }

    SECTION("find 5000") {
        REQUIRE(linear_sentinel<std::uint32_t>(set, 5000));
    }

    SECTION("find 9999") {
        REQUIRE(linear_sentinel<std::uint32_t>(set, 9999));
    }

    SECTION("does not find 10000") {
        REQUIRE_FALSE(linear_sentinel<std::uint32_t>(set, 10000));
    }
}

TEST_CASE("can find item using linear search sentinel ordered", "[algorithm][search][linear]") {
    std::vector<std::uint32_t> set {};

    for (auto i {0u}; i < 10000; ++i) {
        set.push_back(i);
    }

    // we need to use sections because `set` will be modified
    SECTION("find 0") {
        REQUIRE(linear_sentinel_ordered<std::uint32_t>(set, 0));
    }

    SECTION("find 5000") {
        REQUIRE(linear_sentinel_ordered<std::uint32_t>(set, 5000));
    }

    SECTION("find 9999") {
        REQUIRE(linear_sentinel_ordered<std::uint32_t>(set, 9999));
    }

    SECTION("does not find 10000") {
        REQUIRE_FALSE(linear_sentinel_ordered<std::uint32_t>(set, 10000));
    }
}
