#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int solve(int low, int high);
int score(int num);

int main(int argc, char *argv[]) { 
  int t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) {
    int low, high;
    cin >> low >> high;

    printf("%d\n", solve(low, high));
  }
}

int solve(int low, int high) {
  int res = 0;
  int res_ind = low;
  int many = 0;

  for (int ii = low; ii < high + 1; ii++) {
    int val = score(ii);

    if (res <= val) {
      res = val;
      res_ind = ii;
    }
    
    if(many++ > 100)
      break;
  }

  return res_ind;
}

int score(int num) {
  if (num < 10)
    return 0;

  vector<int> res = vector<int>({0, 0, 0, 0, 0, 0});
  int ii = 0;


  while (num > 0) {
    res[ii++] = num % 10;
    num /= 10;
  }

  int minimum = 10;
  int maximum = 0;

  ii--;
  while (ii >= 0) {
    if (res[ii] > maximum)
      maximum = res[ii];

    if (res[ii] < minimum)
      minimum = res[ii];

    ii--;
  }

  return maximum - minimum;
}
