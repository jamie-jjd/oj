#include <iostream>
#include <map>

int main ()
{
  uint64_t n;
  std::cin >> n;
  std::map<uint64_t, uint64_t> tops;
  while (n--)
  {
    uint64_t k;
    std::cin >> k;
    auto it {tops.upper_bound(k)};
    if (it != tops.end())
    {
      if (--std::get<1>(*it) == 0) { tops.erase(it); }
    }
    ++tops[k];
  }
  uint64_t sum {};
  for (auto top : tops) { sum += std::get<1>(top); }
  std::cout << sum << "\n";
  return 0;
}