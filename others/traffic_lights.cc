#include <iostream>
#include <map>

int main ()
{
  uint64_t x {}, n {};
  std::cin >> x >> n;
  std::map<uint64_t, uint64_t> lengths;
  std::map<uint64_t, uint64_t> intervals;
  lengths[x] = 1;
  intervals[0] = x;
  for (uint64_t i {}, p; i != n; ++i)
  {
    std::cin >> p;
    auto [l, r] {*std::prev(intervals.upper_bound(p))};
    if (--lengths[r - l] == 0) { lengths.erase(r - l); }
    intervals[l] = p;
    ++lengths[p - l];
    intervals[p] = r;
    ++lengths[r - p];
    std::cout << std::get<0>(*std::rbegin(lengths)) << "\n";
  }
  return 0;
}