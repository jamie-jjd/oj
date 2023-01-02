#include <iostream>
#include <vector>

int main ()
{
  uint64_t T {};
  std::cin >> T;
  while (T--)
  {
    uint64_t m {};
    uint64_t n {};
    std::cin >> m >> n;
    std::vector<std::string> sequences(m);
    for (uint64_t i {}; i != m; ++i) { std::cin >> sequences[i]; }
    std::string consensus_string;
    uint64_t consensus_error {};
    for (uint64_t c {}; c != n; ++c)
    {
      std::vector<uint64_t> count(4);
      for (uint64_t r {}; r != m; ++r)
      {
        if (sequences[r][c] == 'A')      { ++count[0]; }
        else if (sequences[r][c] == 'C') { ++count[1]; }
        else if (sequences[r][c] == 'G') { ++count[2]; }
        else                             { ++count[3]; }
      }
      uint64_t majority_index {};
      uint64_t majority_count {};
      for (uint64_t i {}; i != 4; ++i)
      {
        if (majority_count < count[i])
        {
          majority_index = i;
          majority_count = count[i];
        }
      }
      if (majority_index == 0)      { consensus_string.push_back('A'); }
      else if (majority_index == 1) { consensus_string.push_back('C'); }
      else if (majority_index == 2) { consensus_string.push_back('G'); }
      else                          { consensus_string.push_back('T'); }
      consensus_error += (m - majority_count);
    }
    std::cout << consensus_string << "\n";
    std::cout << consensus_error << "\n";
  }
  return 0;
}