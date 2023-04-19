#include <iostream>
#include <vector>
#include <set>

using namespace std;

/* Obsy:
 * - zawsze płacimy za dołożenie jedynki
 * - zawsze płacimy za usunięcie duplikatów
 * Koszt po policzeniu tych dwóch = ile_kasować * c + ile_dodać * d
 * Pierwszy pomysł:
 * Wrzucić wszystko na set, 
 * duplikaty = original_input - set.size()
 * dodatnie jedynki = c * [1 \notin set]
 * Usuwamy kolejne rzeczy z seta (bądź dodajemy), mamy
 * koszt_n = koszt_{n - 1} + c [ n \notin set] - d [n \in set]
 *
 */

long long solve(set<int>& values, long long vect_size, int c, int d);

int main() {
  int t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) {
    int n, c, d;
    cin >> n >> c >> d;

    vector<int> almost_permutation(n);
    set<int> values{};

    for (int jj = 0; jj < n; jj++) {
      int temp;
      cin >> temp;
      almost_permutation[jj] = temp;
      values.insert(temp);
    }

    // solve(values, almost_permutation.size(), c, d);
    cout << solve(values, almost_permutation.size(), c, d) << "\n";

  }
}
long long solve(set<int>& values, long long vect_size, int c, int de) {
  // We start by taking permutation of size 1
  long long current_cost;
  long long min_cost;
  long long d = (long long) de;
  if (*values.begin() == 1)
    current_cost = (vect_size - 1) * c;
  else
    current_cost = vect_size * c + d;

  min_cost = current_cost;
  values.insert(1);
  auto it = values.begin();
  int prev = 1;

  while (++it != values.end()) {
    if (*it == prev + 1)
      current_cost -= c;
    else
      current_cost += (*it - prev - 1) * d - c;

    prev = *it;
    min_cost = min(min_cost, current_cost);
  }

  // cout << "========\n";

  return min_cost;
}
