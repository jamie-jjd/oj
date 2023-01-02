#include <iostream>
#include <vector>

int main ()
{
  uint64_t n {};
  uint64_t sum {};
  std::cin >> n >> sum;
  std::vector<uint64_t> a(n);
  for (auto& a_i : a) { std::cin >> a_i; }
  uint64_t count {};
  uint64_t partial_sum {*std::begin(a)};
  auto first {std::begin(a)};
  auto prev_last {std::begin(a)};
  while (prev_last != std::end(a))
  {
    if (partial_sum < sum)
    {
      partial_sum += *(++prev_last);
    }
    else if (partial_sum > sum)
    {
      partial_sum -= *first++;
    }
    else
    {
      ++count;
      partial_sum += *(++prev_last);
      partial_sum -= *first++;
    }
  }
  std::cout << count << "\n";
  return 0;
}
