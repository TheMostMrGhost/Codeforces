#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[])
{
  int  t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) {
    int n;
    cin >> n;

    vector<int> array{};

    for (int jj = 0; jj < n; jj++) {
      cout << 2 * (jj + 1) << " ";
    }
    cout << "\n";
  }

  return 0;
}
