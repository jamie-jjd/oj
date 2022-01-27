#include <algorithm>
#include <iostream>

void AddNumberToSum (std::string& reverse_number, std::string& reverse_sum)
{
  bool is_carry {};
  uint64_t digit {};
  while (reverse_sum.size() < reverse_number.size()) { reverse_sum.push_back('0'); }
  auto it_sum {std::begin(reverse_sum)};
  auto it_number {std::begin(reverse_number)};
  while (it_sum != std::end(reverse_sum) && it_number != std::end(reverse_number))
  {
    auto sum_digit {(*it_sum - '0') + (*it_number - '0') + is_carry};
    is_carry = (sum_digit / 10);
    digit = sum_digit % 10;
    *it_sum = ('0' + digit);
    ++it_sum; ++it_number;
  }
  while (is_carry && it_sum != std::end(reverse_sum))
  {
    if (*it_sum == '9') { *it_sum = '0'; }
    else
    {
      ++(*it_sum);
      is_carry = false;
    }
    ++it_sum;
  }
  if (is_carry) { reverse_sum.push_back('1'); }
  return;
}

void DivideSumByDivisor (std::string const& sum, uint64_t divisor, std::string& quotient)
{
  uint64_t sum_digit {};
  for (auto digit : sum)
  {
    sum_digit = (sum_digit * 10) + (digit - '0');
    if (sum_digit < divisor)
    {
      if (!quotient.empty()) { quotient.push_back('0'); }
    }
    else
    {
      quotient.push_back('0' + (sum_digit / divisor));
      sum_digit %= divisor;
    }
  }
  if (quotient.empty()) { quotient.push_back('0'); }
  return;
}

int main ()
{
  uint64_t N {};
  uint64_t F {};
  uint64_t i {};
  while ((std::cin >> N >> F) && N)
  {
    std::string sum;
    while (N--)
    {
      std::string number;
      std::cin >> number;
      std::reverse(std::begin(number), std::end(number));
      AddNumberToSum(number, sum);
    }
    std::reverse(std::begin(sum), std::end(sum));
    std::cout << "Bill #" << (++i) << " costs " << sum;
    std::string quotient;
    DivideSumByDivisor(sum, F, quotient);
    std::cout << ": each friend should pay " << quotient << "\n\n";
  }
  return 0;
}