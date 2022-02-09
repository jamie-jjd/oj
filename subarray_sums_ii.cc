#include <iostream>
#include <map>
#include <numeric>
#include <vector>

int main ()
{
  uint64_t n {};
  int64_t x {};
  std::cin >> n >> x;
  std::vector<int64_t> a(n);
  uint64_t count {};
  for (auto& a_i : a)
  {
    std::cin >> a_i;
    count += (a_i == x);
  }
  std::vector<int64_t> prefix_sum(a);
  std::partial_sum(std::begin(prefix_sum), std::end(prefix_sum), std::begin(prefix_sum));
  std::map<int64_t, uint64_t> sum_count;
  for (auto sum : prefix_sum)
  {
    auto it {sum_count.find(sum)};
    if (it != sum_count.end()) { ++std::get<1>(*it); }
    else                       { sum_count[sum] = 1; }
  }
  for (uint64_t i {}; i != (n - 1); ++i)
  {
    --sum_count[prefix_sum[i]];
    auto sum {x - a[i] + prefix_sum[i]};
    auto it {sum_count.find(sum)};
    if (it != std::end(sum_count)) { count += std::get<1>(*it); }
  }
  std::cout << count << "\n";
  return 0;
}