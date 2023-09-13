#include <iostream>
#include<set>
#include<string>
#include<vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int ii =0; ii < t; ii++) {
    int n, k;
    cin >> n >> k;
    vector<std::pair<int, int>> a{}, b{}, c{};
    for (int jj =0; jj < n; jj++) {
      int temp;
      cin >> temp;
      a.push_back(make_pair(jj, temp));
    }

    for (int jj =0; jj < n; jj++) {
      int temp;
      cin >> temp;
      b.push_back(make_pair(jj, temp));
    }
    std::sort(a.begin(), a.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
    });

    std::sort(b.begin(), b.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second < rhs.second;
    });
    for (int jj =0; jj < n; jj++) {
      c.push_back(make_pair(a[jj].first, b[jj].second));
    }

    std::sort(c.begin(), c.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.first < rhs.first;
    });

    for (int jj =0; jj < n; jj++) {
      cout << c[jj].second << " ";
    }
    cout << "\n";

  }
}

