#include <algorithm>
#include <iostream>
#include <vector>

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::vector<std::pair<uint64_t, uint64_t>> durations(n);
  for (auto& duration : durations) { std::cin >> std::get<0>(duration) >> std::get<1>(duration); }
  std::sort
  (
    std::begin(durations),
    std::end(durations),
    [] (auto const& lhs, auto const& rhs) { return (std::get<1>(lhs) < std::get<1>(rhs)); }
  );
  uint64_t count {1};
  uint64_t end_time {std::get<1>(*std::begin(durations))};
  for (auto it {std::next(std::begin(durations))}; it != std::end(durations); ++it)
  {
    if (end_time <= std::get<0>(*it))
    {
      ++count;
      end_time = std::get<1>(*it);
    }
  }
  std::cout << count << "\n";
  return 0;
}