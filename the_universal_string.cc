#include <iostream>

int main ()
{
  uint64_t T {};
  std::cin >> T;
  while (T--)
  {
    std::string line;
    std::cin >> line;
    bool is_universal {true};
    auto r {line[0] - 'a'};
    for (uint64_t i {}; i != line.size() && is_universal; ++i)
    {
      is_universal = ((26 + (line[i] - 'a') - r) % 26 == i % 26);
    }
    std::cout << ((is_universal) ? "YES" : "NO") << "\n";
  }
  return 0;
}