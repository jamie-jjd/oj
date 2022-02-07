#include <iostream>
#include <map>
#include <vector>

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::vector<uint64_t> k(n);
  for (auto& k_i : k) { std::cin >> k_i; }
  uint64_t max_count {};
  uint64_t count {};
  uint64_t begin_offset {};
  std::map<uint64_t, uint64_t> prev_offsets;
  for (uint64_t i {}; i != k.size(); ++i)
  {
    auto it {prev_offsets.find(k[i])};
    if (it != std::end(prev_offsets) && begin_offset <= std::get<1>(*it))
    {
      auto prev_offset {std::get<1>(*it)};
      if (max_count < count) { max_count = count; }
      begin_offset = prev_offset + 1;
      count = i - prev_offset;
      std::get<1>(*it) = i;
    }
    else
    {
      prev_offsets[k[i]] = i;
      ++count;
    }
  }
  std::cout << ((max_count < count) ? count : max_count) << "\n";
  return 0;
}