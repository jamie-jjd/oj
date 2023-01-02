#include <iostream>
#include <vector>

int main ()
{
  uint64_t N {};
  uint64_t M {};
  while ((std::cin >> N >> M) && N)
  {
    std::vector<uint64_t> cd_jack(N);
    for (auto& cd : cd_jack) { std::cin >> cd; }
    std::vector<uint64_t> cd_jill(N);
    for (auto& cd : cd_jill) { std::cin >> cd; }
    uint64_t count {};
    auto it_jack {std::begin(cd_jack)};
    auto it_jill {std::begin(cd_jill)};
    while (it_jack != std::end(cd_jack) && it_jill != std::end(cd_jill))
    {
      if (*it_jack < *it_jill)      { ++it_jack; }
      else if (*it_jack > *it_jill) { ++it_jill; }
      else                          { ++count; ++it_jack; ++it_jill; }
    }
    std::cout << count << "\n";
  }
  return 0;
}