#include <iostream>

int main ()
{
  std::string S;
  std::cin >> S;
  std::cout << (S[0] - '0') * (S[2] - '0') << "\n";
  return 0;
}