#include <iostream>
#include <vector>

using namespace std;

bool
is_lt_x (
  vector<size_t> const &p,
  vector<size_t> const &x,
  size_t i
) { return (x[i] > 1 and p[x[i] - 1] < p[x[i]]); }

bool
is_x_lt (
  vector<size_t> const &p,
  vector<size_t> const &x,
  size_t i
) { return (x[i] < p.size() and p[x[i]] < p[x[i] + 1]); }

int
main() {
  size_t n {}, m {}; cin >> n >> m;
  vector<size_t> x(n + 1);
  vector<size_t> p(n + 1);
  for (size_t i {1}; i <= n; ++i) { cin >> x[i]; p[x[i]] = i; }
  size_t s {1};
  for (size_t i {2}; i <= n; ++i) {
    s += (p[i] < p[i - 1]);
  }
  while (m--) {
    size_t a {}, b {}; cin >> a >> b;
    bool is_lt_xa {is_lt_x(p, x, a)}, is_xa_lt {is_x_lt(p, x, a)};
    bool is_lt_xb {is_lt_x(p, x, b)}, is_xb_lt {is_x_lt(p, x, b)};
    swap(p[x[a]], p[x[b]]);
    bool is_lt_xa_ {is_lt_x(p, x, a)}, is_xa_lt_ {is_x_lt(p, x, a)};
    bool is_lt_xb_ {is_lt_x(p, x, b)}, is_xb_lt_ {is_x_lt(p, x, b)};
    if (x[b] != x[a] - 1) {
      s += is_lt_xa and not is_lt_xa_;
      s -= not is_lt_xa and is_lt_xa_;
    }
    if (x[b] != x[a] + 1) {
      s += is_xa_lt and not is_xa_lt_;
      s -= not is_xa_lt and is_xa_lt_;
    }
    s += is_lt_xb and not is_lt_xb_;
    s -= not is_lt_xb and is_lt_xb_;
    s += is_xb_lt and not is_xb_lt_;
    s -= not is_xb_lt and is_xb_lt_;
    cout << s << "\n";
    swap(x[a], x[b]);
  }
  return 0;
}

