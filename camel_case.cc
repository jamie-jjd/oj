#include <cctype>
#include <iostream>

int main ()
{
  uint64_t T {};
  std::cin >> T;
  while (T--)
  {
    std::string line;
    std::cin >> line;
    if (std::islower(line[0]))
    {
      uint64_t count {1};
      for (uint64_t i {1}; i != line.size(); ++i)
      {
        if (std::isupper(line[i])) { ++count; }
      }
      std::cout << ((count <= 7) ? "YES" : "NO") << "\n";
    }
    else { std::cout << "NO\n"; }
  }
  return 0;
}