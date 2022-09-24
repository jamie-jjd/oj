#include <iostream>
#include <map>

int main ()
{
  uint64_t n {};
  while (std::cin >> n && n)
  {
    std::map<uint64_t, uint64_t> urn;
    uint64_t amount {}, k {}, bill {};
    while (n--)
    {
      std::cin >> k;
      while (k--)
      {
        std::cin >> bill;
        auto it {urn.find(bill)};
        if (it != std::end(urn))  { ++std::get<1>(*it); }
        else                      { urn[bill] = 1; }
      }
      amount += (std::get<0>(*std::prev(std::end(urn))) - std::get<0>(*std::begin(urn)));
      if (std::get<1>(*std::prev(std::end(urn))) == 1) { urn.erase(std::get<0>(*std::prev(std::end(urn)))); }
      else                                             { --std::get<1>(*std::prev(std::end(urn))); }
      if (std::get<1>(*std::begin(urn)) == 1) { urn.erase(std::get<0>(*std::begin(urn))); }
      else                                    { --std::get<1>(*std::begin(urn)); }
    }
    std::cout << amount << "\n";
  }
  return 0;
}