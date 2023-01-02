#include <cmath>

#include <iomanip>
#include <iostream>

int main ()
{
  std::string line {};
  while (std::getline(std::cin, line))
  {
    uint64_t H {};
    uint64_t M {};
    if (line[1] == ':')
    {
      H = (line[0] - '0');
      M = (line[2] - '0') * 10 + (line[3] - '0');
    }
    else
    {
      H = (line[0] - '0') * 10 + (line[1] - '0');
      M = (line[3] - '0') * 10 + (line[4] - '0');
    }
    std::cout << std::fixed << std::setprecision(3);
    if (H || M)
    {
      double angle_H = {30 * H + 0.5 * M};
      double angle_M {6.0 * M};
      auto difference {std::fabs(angle_H - angle_M)};
      std::cout << ((difference < 180) ? difference : (360 - difference)) << "\n";
    }
    else { break; }
  }
  return 0;
}
