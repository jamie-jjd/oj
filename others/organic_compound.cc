#include <iomanip>
#include <iostream>

int main ()
{
  uint64_t T {};
  std::cin >> T;
  std::string line;
  std::cout << std::fixed << std::setprecision(3);
  while (T--)
  {
    uint64_t count_C {};
    uint64_t count_H {};
    uint64_t count_O {};
    uint64_t count_N {};
    uint64_t *count {};
    std::cin >> line;
    auto it {std::begin(line)};
    while (*it)
    {
      if (*it == 'C') { count = &count_C; }
      else if (*it == 'H') { count = &count_H; }
      else if (*it == 'O') { count = &count_O; }
      else { count = &count_N; }
      if (++it != std::end(line) && std::isdigit(*it))
      {
        if (std::next(it) != std::end(line) && std::isdigit(*std::next(it)))
        {
          *count += (*it - '0') * 10 + (*std::next(it) - '0');
          it += 2;
        }
        else
        {
          *count += (*it++ - '0');
        }
      }
      else
      {
        ++(*count);
      }
    }
    std::cout << (count_C * 12.01f + count_H * 1.008 + count_O * 16.00 + count_N * 14.01) << "\n";
  }
  return 0;
}
