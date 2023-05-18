#include <iostream>
#include <vector>

using namespace std;


int solve(vector<int> & arr);
int gcd(int a, int b);
int gcd_array(vector<int> &arr);
int max_array(vector<int> &arr);

int main (int argc, char *argv[])
{
  int  t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) {
    int n;
    cin >> n;

    vector<int> array{};

    for (int jj = 0; jj < n; jj++) {
      int temp;
      cin >> temp;
      array.push_back(temp);
    }
    cout << solve(array) << "\n";
  }

  return 0;
}

int solve(vector<int> & arr) {
  vector<int> inv{};

  bool all_zero = true;

  for( int ii = 0; ii < arr.size(); ii++) {
    inv.push_back(abs(arr[ii] - ii - 1));
    all_zero = all_zero && arr[ii] - ii == 0;
  }

  if(all_zero)
    return arr.size();

  // for (auto elem: inv)
  //   cout << elem << " ";
  // cout <<"\n";
  return gcd_array(inv);
}

int gcd(int a, int b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

int gcd_array(vector<int> &arr) {
  int temp = 0;
  while (arr[temp] == 0)
    temp++;

  int result = arr[temp];
  for (int i = temp + 1; i < arr.size(); i++) {
    if (arr[i] != 0)
      result = gcd(result, arr[i]);
  }
  return result;
}

int max_array( vector<int> &arr) {
    int max = arr.at(0);
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr.at(i);
        }
    }
    return max;
}
