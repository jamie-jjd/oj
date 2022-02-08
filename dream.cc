#include <iostream>
#include <vector>

int main ()
{
  uint64_t n {};
  std::string line;
  std::getline(std::cin, line);
  n = std::stoull(line);
  std::vector<std::string> names;
  while (n--)
  {
    std::getline(std::cin, line);
    if (line[0] == 'S')       { names.push_back(line.substr(6)); }
    else if (line[0] == 'K')  { if (!names.empty()) { names.pop_back(); } }
    else                      { std::cout << ((names.empty()) ? "Not in a dream" : names.back()) << "\n"; }
  }
  return 0;
}