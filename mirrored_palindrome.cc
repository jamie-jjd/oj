#include <iostream>
#include <vector>

int main ()
{
  std::vector<char> reverse(256);
  {
    reverse['A'] = 'A'; reverse['E'] = '3'; reverse['H'] = 'H';
    reverse['I'] = 'I'; reverse['J'] = 'L'; reverse['L'] = 'J';
    reverse['M'] = 'M'; reverse['O'] = 'O'; reverse['S'] = '2';
    reverse['T'] = 'T'; reverse['U'] = 'U'; reverse['V'] = 'V';
    reverse['W'] = 'W'; reverse['X'] = 'X'; reverse['Y'] = 'Y';
    reverse['Z'] = '5'; reverse['1'] = '1'; reverse['2'] = 'S';
    reverse['3'] = 'E'; reverse['5'] = 'Z'; reverse['8'] = '8';
  }
  std::vector<bool> is_reverse(256);
  {
    is_reverse['A'] = is_reverse['H'] = is_reverse['I']
    = is_reverse['I'] = is_reverse['M'] = is_reverse['O']
    = is_reverse['T'] = is_reverse['U'] = is_reverse['V']
    = is_reverse['W'] = is_reverse['X'] = is_reverse['Y']
    = is_reverse['1'] = is_reverse['8'] = true;
  }
  std::string line;
  while (std::getline(std::cin, line))
  {
    auto is_palindrome {true};
    auto is_mirrored {true};
    for (uint64_t i {}; i != (line.size() >> 1) && is_palindrome; ++i)
    {
      is_palindrome &= (*std::next(std::begin(line), i) == (*std::next(line.rbegin(), i)));
    }
    for (uint64_t i {}; i != (line.size() >> 1) && is_mirrored; ++i)
    {
      is_mirrored &= (*std::next(std::begin(line), i) == reverse[(*std::next(line.rbegin(), i))]);
    }
    if (line.size() & 1) { is_mirrored &= is_reverse[line[line.size() >> 1]]; }
    if (is_mirrored && is_palindrome)
    {
      std::cout << line << " -- is a mirrored palindrome.\n";
    }
    else if (is_mirrored)
    {
      std::cout << line << " -- is a mirrored string.\n";
    }
    else if (is_palindrome)
    {
      std::cout << line << " -- is a regular palindrome.\n";
    }
    else
    {
      std::cout << line << " -- is not a palindrome.\n";
    }
    std::cout << "\n";
  }
  return 0;
}