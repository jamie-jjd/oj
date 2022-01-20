#include <iostream>
#include <vector>

void CalculateIsComposite (std::vector<bool>& is_composite)
{
  std::vector<uint64_t> primes;
  is_composite[0] = is_composite[1] = true;
  for (uint64_t i {2}; i != is_composite.size(); ++i)
  {
    if (!is_composite[i]) { primes.push_back(i); }
    for (auto const& prime : primes)
    {
      if (i * prime < is_composite.size())
      {
        is_composite[i * prime] = true;
      }
      else { break; }
    }
  }
  return;
}

int main ()
{
  std::vector<bool> is_composite(1'000'001);
  CalculateIsComposite(is_composite);
  uint64_t t {};
  std::cin >> t;
  while (t--)
  {
    uint64_t n {};
    uint64_t e {};
    std::cin >> n >> e;
    std::vector<uint64_t> a(n);
    for (auto& x : a) { std::cin >> x; }
    uint64_t count {};
    for (uint64_t i {}; i != e; ++i)
    {
      bool is_after_prime {};
      uint64_t count_prev_1 {};
      uint64_t count_next_1 {};
      for (uint64_t j {i}; j < n; j += e)
      {
        if (a[j] == 1)
        {
          if (is_after_prime) { ++count_next_1; }
          else { ++count_prev_1; }
        }
        else
        {
          if (is_after_prime && (count_prev_1 || count_next_1))
          {
            count += count_prev_1 * (1 + count_next_1) + count_next_1;
          }
          if (is_composite[a[j]])
          {
            count_prev_1 = count_next_1 = 0;
            is_after_prime = false;
          }
          else
          {
            if (is_after_prime) { count_prev_1 = count_next_1; }
            count_next_1 = 0;
            is_after_prime = true;
          }
        }
      }
      if (is_after_prime && (count_prev_1 || count_next_1))
      {
        count += count_prev_1 * (1 + count_next_1) + count_next_1;
      }
    }
    std::cout << count << "\n";
  }
  return 0;
}
