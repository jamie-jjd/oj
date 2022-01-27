#include <iostream>

int main ()
{
  uint64_t N {};
  std::cin >> N;
  while (N--)
  {
    std::string integer_0 {};
    std::string integer_1 {};
    std::cin >> integer_0 >> integer_1;
    bool is_leading_zero {true};
    bool is_carry {};
    uint64_t digit {};
    auto it_0 {std::begin(integer_0)};
    auto it_1 {std::begin(integer_1)};
    while (it_0 != std::end(integer_0) && it_1 != std::end(integer_1))
    {
      auto sum_digit {(*it_0++ - '0') + (*it_1++ - '0') + is_carry};
      is_carry = (sum_digit / 10);
      digit = sum_digit % 10;
      is_leading_zero &= (digit == 0);
      if (!is_leading_zero) { std::cout << digit; }
    }
    while (it_0 != std::end(integer_0))
    {
      auto digit {(*it_0 - '0' + is_carry) % 10};
      is_carry = (is_carry && (*it_0 == '9'));
      is_leading_zero &= (digit == 0);
      if (!is_leading_zero) { std::cout << digit; }
      ++it_0;
    }
    while (it_1 != std::end(integer_1))
    {
      auto digit {(*it_1 - '0' + is_carry) % 10};
      is_carry = (is_carry && (*it_1 == '9'));
      is_leading_zero &= (digit == 0);
      if (!is_leading_zero) { std::cout << digit; }
      ++it_1;
    }
    if (is_carry) { std::cout << "1"; }
    std::cout << "\n";
  }
  return 0;
}