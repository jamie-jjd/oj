#include <iostream>
#include <vector>

int main ()
{
  int64_t n {};
  std::cin >> n;
  int64_t count {};
  std::vector<int64_t> a(n);
  for (auto& a_i : a)
  {
    std::cin >> a_i;
    a_i %= n;
    if (a_i < 0) { a_i += n; }
    if (a_i == 0) { ++count; }
  }
  for (int64_t i {1}; i != n; ++i) { a[i] = (a[i] + a[i - 1]) % n; }
  std::vector<int64_t> count_r(n);
  for (auto r : a) { ++count_r[r]; }
  for (int64_t i {}; i != n; ++i)
  {
    auto r_i {(i) ? ((n + a[i] - a[i - 1]) % n) : a[i]};
    --(count_r[a[i]]);
    count += count_r[(n - r_i + a[i]) % n];
  }
  std::cout << count << "\n";
  return 0;
}