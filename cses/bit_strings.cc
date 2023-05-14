#include <iostream>

int
main() {
  uint64_t n {};
  std::cin >> n;
  uint64_t num {1};
  uint64_t p {2};
  while (n) {
    if (n & 1) { num = (num * p) % 1'000'000'007; }
    p = (p * p) % 1'000'000'007;
    n >>= 1;
  }
  std::cout << num << "\n";
  return 0;
}
