#include <iostream>
#include<set>
#include<vector>
#include<string>
#include<limits>

using namespace std;



int findMinimumEven(const std::vector<int>& arr) {

    int minEven = std::numeric_limits<int>::max();
    for (const int& num : arr) {
        if (num % 2 == 0 && num < minEven) {
            minEven = num;
        }
    }

    return (minEven != std::numeric_limits<int>::max()) ? minEven : -1;
}

int findMinimumOdd(const std::vector<int>& arr) {

    int minEven = std::numeric_limits<int>::max();
    for (const int& num : arr) {
        if (num % 2 == 1 && num < minEven) {
            minEven = num;
        }
    }

    return (minEven != std::numeric_limits<int>::max()) ? minEven : -1;
}

int main() {
  int t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) {
    int num;
    cin >> num;
    vector<int> nums{};


    for (int jj = 0; jj < num; jj++) {
      int temp;
      cin >> temp;
      nums.push_back(temp);
    }

    int mine = findMinimumEven(nums);
    int minodd = findMinimumOdd(nums);

    if (mine == -1 || minodd == -1 || mine > minodd)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }
}

