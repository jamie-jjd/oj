#include <iostream>
#include <vector>

std::ostream& operator<< (std::ostream& out, std::vector<uint64_t> const& v) {
  auto it {v.begin()};
  if (it != v.end()) {
    out << *it++;
    while (it != v.end()) { out << " " << *it++; }
  }
  return out;
}

void DFS (
  std::vector<uint64_t> const& A,
  uint64_t d,
  uint64_t o,
  std::vector<uint64_t>& C
) {
  if (d == C.size()) {
    std::cout << C << "\n";
    return;
  }
  for (uint64_t i {o}; i != A.size(); ++i) {
    if (d == 0 || C[d - 1] < A[i]) {
      C[d] = A[i];
      DFS(A, d + 1, i + 1, C);
    }
  }
  return;
}

int main () {
  uint64_t N, M;
  while (std::cin >> N >> M) {
    std::vector<uint64_t> A(N), C(M);
    for (auto& a : A) { std::cin >> a; }
    DFS(A, 0, 0, C);
  }
  return 0;
}
