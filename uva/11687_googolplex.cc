#include <iostream>

int main ()
{
  std::string googol;
  while (std::cin >> googol)
  {
    if (googol[0] != 'E')
    {
      if (googol.size() == 1 && googol[0] == '1')
      {
        std::cout << "1\n";
      }
      else if (googol.size() == 1)
      {
        std::cout << "2\n";
      }
      else if (googol.size() < 10)
      {
        std::cout << "3\n";
      }
      else
      {
        std::cout << "4\n";
      }
    }
  }
  return 0;
}
