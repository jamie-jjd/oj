#include <iostream>
#include <vector>

int main ()
{
  uint64_t n {};
  std::cin >> n;
  std::vector<std::vector<bool>> gray_code(1);
  for (uint64_t i {}; i != n; ++i)
  {
    for (uint64_t j {}; j != (1ULL << i); ++j)
    {
      gray_code[j].push_back(false);
    }
    for (uint64_t j {}; j != (1ULL << i); ++j)
    {
      gray_code.push_back(gray_code[(1ULL << i) - 1 - j]);
      *std::rbegin(gray_code[(1ULL << i) + j]) = true;
    }
  }
  for (auto const& bits : gray_code)
  {
    for (auto it {std::rbegin(bits)}; it != std::rend(bits); ++it)
    {
      std::cout << *it;
    }
    std::cout << "\n";
  }
  return 0;
}
