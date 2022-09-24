#include <cmath>
#include <iostream>

int main ()
{
  uint64_t T {};
  std::cin >> T;
  while (T--)
  {
    uint64_t x_0 {}, y_0 {}, x_1 {}, y_1 {};
    std::cin >> x_0 >> y_0 >> x_1 >> y_1;
    auto diff_x {(x_0 < x_1) ? (x_1 - x_0) : (x_0 - x_1)};
    auto diff_y {(y_0 < y_1) ? (y_1 - y_0) : (y_0 - y_1)};
    std::cout << (diff_x + diff_y) << "\n";
  }
  return 0;
}