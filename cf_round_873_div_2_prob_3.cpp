#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solve(vector<int> & arr);

int main (int argc, char *argv[])
{
  int  t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) {
    int n;
    cin >> n;

    vector<int> a{}, b{};

    for (int jj = 0; jj < n; jj++) {
      int temp;
      cin >> temp;
      a.push_back(temp);
    }

    for (int jj = 0; jj < n; jj++) {
      int temp;
      cin >> temp;
      b.push_back(temp);
    }


    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long res = 1;
    // cout << " ===========\n";
    for (int jj = 0; jj < n; jj++) {
      res *=(long long) (lower_bound(b.begin(), b.end(), a[jj]) - b.begin() - jj) % (1000000000 + 7);
      res %=(1000000000 + 7);
    }
    // cout << " ===========\n";
    cout << res << "\n";
  }

  return 0;
}

