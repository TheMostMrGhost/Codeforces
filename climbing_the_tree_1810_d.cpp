#include <iostream>
#include <tuple>

using namespace std;
constexpr long long max_int = 2000000000000000000;
// #define MAX(A, B)               ((A) > (B) ? (A) : (B))

pair<long long, long long> adjust_height(pair<long long, long long> previous_height, 
    long long a, long long b, int n); // previous_height is a two-side closed interval that 
                          // contains the real height

// Calculates number of days needed to climb a tree, if not possible returns -1
long long answer(pair<long long, long long> height, long long a, long long b);

int main (int argc, char *argv[]) {
  int t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) {
    int q;
    cin >> q;

    pair<long long, long long> height = make_pair(0, max_int);

    for (int jj = 0; jj < q; jj++) {
      int option;
      cin >> option;

      if (option == 1) {
        long long a, b;
        int n;
        cin >> a >> b >> n;

        pair<long long, long long> new_height = adjust_height(height, a, b, n);

        if (new_height.first > -1) {
          cout << 1 << " ";
          height = new_height;
        }
        else
          cout << 0 << " ";
      }
      else {
        long long a, b;
        cin >> a >> b;
        long long ans = answer(height, a, b);
        cout << ans << " ";
      }
    }

    cout << "\n";
  }
}

pair<long long, long long> 
adjust_height(pair<long long, long long> previous_height, long long a, long long b, int n) {
  if (n == 1) {
    if (a < previous_height.first)
      return make_pair(-1, -1);
    return make_pair(previous_height.first,  min(previous_height.second, (long long) a));
  }

  long long new_lower = (n - 2) * (a - b) + a + 1, new_higher = (n - 1) * (a - b) + a;

  if (new_higher < previous_height.first || new_lower > previous_height.second)
    return make_pair(-1, -1);

  return make_pair(max(previous_height.first, new_lower), min(previous_height.second, new_higher));
}

long long answer(pair<long long, long long> height, long long a, long long b) {
  long long n1 = -2, n2 = -1;

  if (a >= height.second)
    return 1;

  n1 = height.first - a - 1;
  n2 = height.second - a;
  if (height.second <= a)
    return 1;

  if (n2 - n1 <= a - b) {
    long long res = n1 / (a - b) + 2;
    if ((res - 2) * (a - b) + a + 1 <= height.first && (res - 1) * (a - b) + a >= height.second)
      return res;
  }
  return -1;
}
