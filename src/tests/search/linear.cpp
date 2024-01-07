#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

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

    BENCHMARK_ADVANCED("beginning of list")(Catch::Benchmark::Chronometer meter) {
        std::vector<std::uint32_t> bench_set {};

        for (auto i {0u}; i < 10000000; ++i) {
            set.push_back(i);
        }

        meter.measure([&](int i) { return linear_basic<std::uint32_t>(set, 0); });
    };
}

TEST_CASE("benchmark: can find item using linear search basic", "[benchmark][algorithm][search][linear]") {
    std::vector<std::uint32_t> set {};

    for (auto i {0u}; i < 10000000; ++i) {
        set.push_back(i);
    }

    BENCHMARK("beginning of list") {
        return linear_basic<std::uint32_t>(set, 0);
    };

    BENCHMARK("middle of list") {
        return linear_basic<std::uint32_t>(set, 10000000 / 2);
    };

    BENCHMARK("end of list") {
        return linear_basic<std::uint32_t>(set, 10000000 - 1);
    };

    BENCHMARK("value not found") {
        return linear_basic<std::uint32_t>(set, 10000000);
    };
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

TEST_CASE("benchmark: can find item using linear search sentinel", "[benchmark][algorithm][search][linear]") {
    std::vector<std::uint32_t> set {};

    for (auto i {0u}; i < 10000000; ++i) {
        set.push_back(i);
    }

    BENCHMARK("beginning of list") {
        return linear_sentinel<std::uint32_t>(set, 0);
    };

    BENCHMARK("middle of list") {
        return linear_sentinel<std::uint32_t>(set, 10000000 / 2);
    };

    BENCHMARK("end of list") {
        return linear_sentinel<std::uint32_t>(set, 10000000 - 1);
    };

    BENCHMARK("value not found") {
        return linear_sentinel<std::uint32_t>(set, 10000000);
    };
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

TEST_CASE("benchmark: can find item using linear search sentinel ordered", "[benchmark][algorithm][search][linear]") {
    std::vector<std::uint32_t> set {};

    for (auto i {0u}; i < 10000000; ++i) {
        set.push_back(i);
    }

    BENCHMARK("beginning of list") {
        return linear_sentinel_ordered<std::uint32_t>(set, 0);
    };

    BENCHMARK("middle of list") {
        return linear_sentinel_ordered<std::uint32_t>(set, 10000000 / 2);
    };

    BENCHMARK("end of list") {
        return linear_sentinel_ordered<std::uint32_t>(set, 10000000 - 1);
    };

    BENCHMARK("value not found") {
        return linear_sentinel_ordered<std::uint32_t>(set, 10000000);
    };
}
