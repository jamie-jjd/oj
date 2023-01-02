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
    auto& sum {(integer_0.size() < integer_1.size()) ? integer_1 : integer_0};
    auto& integer {(integer_0.size() < integer_1.size()) ? integer_0 : integer_1};
    bool is_carry {};
    uint64_t digit {};
    auto it_sum {std::begin(sum)};
    auto it_integer {std::begin(integer)};
    while (it_sum != std::end(sum) && it_integer != std::end(integer))
    {
      auto sum_digit {(*it_sum - '0') + (*it_integer - '0') + is_carry};
      is_carry = (sum_digit / 10);
      *it_sum = ('0' + sum_digit % 10);
      ++it_sum; ++it_integer;
    }
    while (is_carry && it_sum != std::end(sum))
    {
      if (*it_sum == '9') { *it_sum = '0'; }
      else
      {
        ++(*it_sum);
        is_carry = false;
      }
      ++it_sum;
    }
    if (is_carry) { sum.push_back('1'); }
    while (sum.back() == '0') { sum.pop_back(); }
    bool is_leading_zero {true};
    for (auto const& digit : sum)
    {
      is_leading_zero &= (digit == '0');
      if (!is_leading_zero) { std::cout << digit; }
    }
    std::cout << "\n";
  }
  return 0;
}