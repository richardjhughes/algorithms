#pragma once

#include <vector>

namespace algorithms::search::linear {

// all algorithms here are based on this source:
// https://en.wikipedia.org/wiki/Linear_search

// performs a linear search on an unordered `set` to find `target`
// complexity: O(n)
// @param set the set to search
// @param target the element to search for
// @returns true if found, else false
template <typename T>
[[nodiscard]] auto linear_basic(const std::vector<T> &set, const T &target)
    -> bool {
  for (const auto &element : set) {
    if (element == target) {
      return true;
    }
  }

  return false;
}

// Performs a linear search on an unordered `set` to find `target`.
// It inserts a sentinel value, `target`, to the end of
// the list and guarantees the search ends of this sentinel value is hit.
// This is to remove the conditional check of `index < std::size(set)`.
// complexity: O(n)
// @param set the set to search
// @param target the element to search for
// @returns true if found, else false
template <typename T>
[[nodiscard]] auto linear_sentinel(std::vector<T> &set, const T &target)
    -> bool {
  set.push_back(target);

  auto index{0u};
  while (set[index++] != target)
    ;

  // return false if the sentinel value was hit
  return index - 1 != std::size(set) - 1;
}

// Performs a linear search on an ordered `set` to find `target`.
// It inserts a sentinel value, `target + 1`, to the end of
// the list and guarantees the search ends of this sentinel value is hit.
// Instead of checking if `set[i] == target`, this checks if `set[i] > target`.
// This enables an early exit from the loop, as if the element is greater than
// `target`, `target` will not be in `set`.
// This is to remove the conditional check of `index < std::size(set)`.
// complexity: O(n)
// @param set the set to search
// @param target the element to search for
// @returns true if found, else false
template <typename T>
[[nodiscard]] auto linear_sentinel_ordered(std::vector<T> &set, const T &target)
    -> bool {
  set.push_back(target + 1);

  auto index{0u};
  while (set[index++] < target)
    ;

  const auto result = set[index - 1] == target;
  return result;
}
} // namespace algorithms::search::linear
