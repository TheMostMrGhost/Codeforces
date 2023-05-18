#include <iostream>
#include <vector>

using namespace std;

bool answer(vector<int>& array);

int main (int argc, char *argv[]) {
  int t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) { 
    int n;
    scanf("%d", &n);
    // cout << n << " ";

    vector<int> array(n);


    // cout << array.size();
    for (int jj = 0; jj < n; jj++)
      cin >> array[jj];

    if (n % 2  == 1 || answer(array))
      printf("YES\n");
    else
      printf("NO\n");
  }
}

bool answer(vector<int>& array) {
  long long sum = 0;
  
  // cout << array.size();
  for (int ii = 0; ii < array.size(); ii += 2) {
    // cout << sum << " ";
    // cout << ii << "| " << array[ii] << " " << array[ii + 1] << "\n";
    sum += (long long) (array[ii + 1] - array[ii]);
  }

  return sum >= 0;
}
