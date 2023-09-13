#include <iostream>
#include<set>
#include<vector>
#include<string>
#include<limits>

using namespace std;

int find_max(const vector<int>& vectorrrro, int num);
int max_interval(const vector<int>& vectorrrro);
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
    max_interval(nums);


  }
}

int find_max(const vector<int>& vectorrrro, int num) {
  int ii = 0;

  if (vectorrrro[vectorrrro.size() - 1] == num)
    return vectorrrro.size() - 1;
  while (vectorrrro[ii++] != num);
  return ii - 1;
}

int max_interval(const vector<int>& vectorrrro) {

  bool sorted = true;
  
  int index = 0;
    for (int ii = 0; ii < vectorrrro.size(); ii++) {
      sorted = sorted && vectorrrro[ii] == vectorrrro.size() - ii;
      if (!sorted) {
        index = ii;
        break;
      }
    }

    // if (sorted) {
    // }



  
  if(!sorted) {
    int r = find_max(vectorrrro, vectorrrro.size() - index) - 1;
    int l = r;

    if (r != vectorrrro.size() - 1) {
      while (l > index && vectorrrro[l - 1] < vectorrrro[vectorrrro.size() - 1]) {
        l--;
      }
    }
    else {
      r = vectorrrro.size() - 1 ;
      l = r;
    }
      // cout << "\n==========\n";
      // cout << "l " << l << " " << "r " << r << endl;
      // cout << "\n==========\n";

      for (int ii = r + 1; ii < vectorrrro.size(); ii++) {
        cout << vectorrrro[ii] << " ";
      }

      for (int ii = r; ii >= l; ii--) {
        cout << vectorrrro[ii] << " ";
      }

      for (int ii = 0; ii < l; ii++) {
        cout << vectorrrro[ii] << " ";
      }
    
  } 
  else {

    // cout << "Dupasdflkjasdf";
    for (int ii = 1; ii < vectorrrro.size(); ii++) {
      cout << vectorrrro[ii] << " ";
    }
    cout << vectorrrro[0] << " ";
    //
    // int next = vectorrrro.size() - 1;
    // int pos = 1;
    // while (vectorrrro[pos++] == next--) {cout << vectorrrro[pos] << " ";}
    // if (pos < vectorrrro.size()) {
    //   max_interval(std::vector<int>(vectorrrro.begin() + pos, vectorrrro.end()));
    // }
  }
  cout << endl;
// 
 return 0;
}
