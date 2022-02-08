#include <algorithm>
#include <iostream>
#include <vector>

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::vector<std::pair<uint64_t, bool>> time_points(2 * n);
  for (uint64_t i {}; i != time_points.size(); i += 2)
  {
    std::cin >> std::get<0>(time_points[i]) >> std::get<0>(time_points[i + 1]);
    std::get<1>(time_points[i]) = true;
    std::get<1>(time_points[i + 1]) = false;
  }
  std::sort
  (
    std::begin(time_points),
    std::end(time_points),
    [] (auto const& lhs, auto const& rhs) { return (std::get<0>(lhs) < std::get<0>(rhs)); }
  );
  uint64_t max_count {};
  uint64_t count {};
  for (auto const& time_point : time_points)
  {
    if (std::get<1>(time_point)) { ++count; }
    else                         { --count; }
    if (max_count < count) { max_count = count; }
  }
  std::cout << max_count << "\n";
  return 0;
}