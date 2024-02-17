#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll t;
ll n;
vl A;

ll ans;
vl sel;
void solve(ll b) {
  if (sel.size() == 2) {
    ans += gcd(sel[0], sel[1]);
    return;
  }

  for (auto i = b; i < A.size(); ++i) {
    sel.push_back(A[i]);
    solve(i + 1);
    sel.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> t;
  while (0 < (t--)) {
    cin >> n;

    A = vl(n);
    for (auto&& a : A) {
      cin >> a;
    }

    ans = 0;
    solve(0);
    cout << ans << '\n';
  }

  return 0;
}