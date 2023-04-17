#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second > b.second;
}

void print_vector(const vector<int> &vect);
int main (int argc, char *argv[]) {
  int t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) {
    int n, s1, s2;
    cin >> n >> s1 >> s2;

    vector<pair<int, int>> requests(n);

    for (int jj = 0; jj < n; jj++) {
      int temp;
      cin >> temp;
      requests[jj] = make_pair(jj, temp);
    }

    sort(requests.begin(), requests.end(), comparePairs);

    // for (auto& elem : requests)
    //   cout << elem.first ;//<< " " << elem.second;
    // cout << endl;
    // for (auto& elem : requests)
    //   cout << elem.second ;//<< " " << elem.second;

    vector<int> a{}, b{}; // Zakładamy, że a jest szybszy i najwyżej w wyniku zamieniamy kolejność

    bool swith = s2 < s1;
    if (s2 < s1) {
      int c = s1;
      s1 = s2;
      s2 = c;
    }

    // cout << s1 << " " << s2 << endl;

    for (int jj = 0; jj < requests.size(); jj++) {
      if ((a.size() + 1) * s1 <= (b.size() + 1) *  s2) {
        a.push_back(requests[jj].first + 1);
      }
      else {
        b.push_back(requests[jj].first + 1);
      }
    }

    if (swith) {
      print_vector(b);
      print_vector(a);
    }
    else {
      print_vector(a);
      print_vector(b);
    }

  }
  
}

void print_vector(const vector<int> &vect) {
  cout << vect.size();

  for (int ii = 0; ii < vect.size(); ii++)
    cout << " " << vect[ii];
  cout << "\n";
}
