#include <iostream>
#include <vector>

int main ()
{
  uint64_t H, W;
  std::cin >> H >> W;
  std::string line;
  std::vector<uint64_t> count(W);
  count[0] = 1;
  while (H--)
  {
    std::cin >> line;
    if (line[0] == '#') { count[0] = 0; }
    for (uint64_t i {1}; i != W; ++i)
    {
      if (line[i] == '.') { count[i] = (count[i] + count[i - 1]) % 1'000'000'007; }
      else                { count[i] = 0; }
    }
  }
  std::cout << *(count.rbegin()) << "\n";
  return 0;
}