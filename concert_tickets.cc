#include <iostream>
#include <map>

int main ()
{
  uint64_t n {}, m {};
  std::cin >> n >> m;
  std::map<uint64_t, uint64_t> h;
  uint64_t h_i {};
  while (n--)
  {
    std::cin >> h_i;
    auto it {h.find(h_i)};
    if (it != std::end(h)) { ++std::get<1>(*it); }
    else                   { h[h_i] = 1; }
  }
  uint64_t t_i {};
  while (m--)
  {
    std::cin >> t_i;
    auto it {h.lower_bound(t_i)};
    if (it == std::end(h) || std::get<0>(*it) != t_i) { it = (it != std::begin(h)) ? std::prev(it) : std::end(h); }
    if (it != std::end(h))
    {
      std::cout << std::get<0>(*it) << "\n";
      if (std::get<1>(*it) == 1) { h.erase(it); }
      else                       { --std::get<1>(*it); }
    }
    else { std::cout << "-1\n"; }
  }
  return 0;
}