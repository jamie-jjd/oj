#include <iostream>
#include <vector>

int main ()
{
  uint64_t numerator {};
  uint64_t denominator {};
  while (std::cin >> numerator >> denominator)
  {
    std::cout << numerator << "/" << denominator << " = ";
    uint64_t integral_part {numerator / denominator};
    std::cout << integral_part << ".";
    std::vector<uint64_t> quotient;
    std::vector<uint64_t> prev_offsets(denominator * 10, 0);
    uint64_t offset {1};
    auto remainder {(numerator % denominator) * 10};
    while (remainder)
    {
      quotient.push_back(remainder / denominator);
      if (prev_offsets[remainder])
      {
        uint64_t i {1};
        while (i != prev_offsets[remainder]) { std::cout << quotient[i - 1]; ++i; }
        std::cout << "(";
        while (i != quotient.size() && i <= 50) { std::cout << quotient[i - 1]; ++i; }
        if (quotient.size() >= 50) { std::cout << "..."; }
        std::cout << ")";
        std::cout << "\n";
        std::cout << "   " << (offset - prev_offsets[remainder]) << " = number of digits in repeating cycle\n";
        break;
      }
      else
      {
        prev_offsets[remainder] = offset++;
      }
      remainder = (remainder % denominator) * 10;
    }
    if (remainder == 0)
    {
      for (auto const& digit : quotient) { std::cout << digit; }
      std::cout << "(0)\n";
      std::cout << "   1 = number of digits in repeating cycle\n";
    }
    std::cout << "\n";
  }
  return 0;
}