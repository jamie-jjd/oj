#include <iostream>

int main ()
{
  std::string line;
  std::cin >> line;
  char prev_c {};
  uint64_t max_count {};
  uint64_t count {};
  for (auto const& c : line)
  {
    if (prev_c != c)
    {
      prev_c = c;
      if (max_count < count) { max_count = count; }
      count = 1;
    }
    else
    {
      ++count;
    }
  }
  std::cout << ((max_count < count) ? count : max_count) << "\n";
  return 0;
}
