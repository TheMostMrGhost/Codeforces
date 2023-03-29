#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
using lint = long long unsigned int;

lint solve(lint low, lint high);
vector<int> parse_number(lint num);
void print_vec(vector<vector<int>> tab);

int main(int argc, char *argv[]) { 
  int t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) {
    long long unsigned int low, high;
    cin >> low >> high;

    printf("%llu\n", solve(low, high));
  }
}

lint solve(lint low, lint high) {

  if (low < 10 && high < 10)
    return 0;

  vector<vector<int>> tab = vector<vector<int>>{};

  for (int ii = 0; ii < 18; ii++) {
    tab.push_back(vector<int>{});

    for (int jj = 0; jj < 10; jj++)
      tab[ii].push_back(10);
  }

  vector<int> parsed_low = parse_number(low);
  vector<int> parsed_high = parse_number(high);

  if (parsed_low.size() != parsed_high.size())
    return 0;

  int ind = parsed_high.size() - 1;

  while (parsed_high[ind] == parsed_low[ind] && ind-- > 0);

  int save_ind = ind;

  if (ind < 0)
    return low; // low == high

  for (int ii = parsed_low[save_ind]; ii < parsed_high[save_ind] + 1; ii++)
    tab[save_ind][ii] = 0;

  // print_vec(tab);

  if (ind < 0) {
    int min_val = 10;
    int max_val = 0;

    for (int ii = 0; ii < parsed_low.size(); ii++) {
      min_val = min(parsed_low[ii], min_val);
      max_val = max(parsed_low[ii], max_val);
    }

    int min_val_low = min_val;
    int min_val_high = max_val;

    min_val = 10;
    max_val = 0;

    for (int ii = 0; ii < parsed_high.size(); ii++) {
      min_val = min(parsed_high[ii], min_val);
      max_val = max(parsed_high[ii], max_val);
    }

    if (max_val - min_val > min_val_high - min_val_low)
      return high;
    return low;
  }

  int min_val = 10;
  int max_val = 0;

  // cout << "saveind " << save_ind << " " << parsed_low[save_ind] << endl;
  for (int ii = save_ind; ii < parsed_low.size(); ii++) {
    min_val = min(parsed_low[ii], min_val);
    max_val = max(parsed_low[ii], max_val);
  }

  cout << min_val << " " << max_val << endl;

  for(int kk = 0; kk < 2 && ind >= 0; kk++) {
    for (int ii = parsed_low[ind]; ii < parsed_high[ind]; ii++) {
      if (ii > max_val)
        tab[ind][ii] = ii - max_val;
      else if (ii < min_val)
        tab[ind][ii] = min_val - ii;
      else
        tab[ind][ii] = 0;
    }
    ind--;
  }

  while (ind >= 0) {
    for (int ii = 0; ii < 10; ii++) {
      if (ii > max_val)
        tab[ind][ii] = ii - max_val;
      else if (ii < min_val)
        tab[ind][ii] = min_val - ii;
      else
       tab[ind][ii] = 0;
    }
    ind--;
  }

  print_vec(tab);

  vector<int> res = vector<int>{};

  for (int ii = save_ind - 1; ii >= 0; ii--) {
    res.push_back(10);
    int mini = 10;

    for (int jj = 0; jj < 10; jj++)
      if (tab[ii][jj] < mini) {
        res[res.size() - 1] = jj;
        mini = tab[ii][jj];
      }
  }

  lint result = 0;
  lint multiplyer = 1;

  for (int ii = 0; ii < res.size(); ii++) {
    // cout << res[ii] << " ";
    result += res[ii] * multiplyer;
    multiplyer *= 10;
  }
  // cout << endl;

  for (int ii = res.size(); ii < parsed_low.size(); ii++) {
    // cout << "dupa" << endl;
    result += parsed_low[ii] * multiplyer;
    multiplyer *= 10;
  }

  return result;
}

vector<int> parse_number(lint num) {
  vector<int> res = vector<int>{};

  if (num < 10) {
    res.push_back(num);
    return res;
  }
    
  while (num > 0) {
    res.push_back(num % 10);
    num /= 10;
  }

  return res; 
}

void print_vec(vector<vector<int>> tab) {
  for (int ii = 0; ii < tab.size(); ii++) {
    cout << "ii " << ii << "| ";
    for (int jj = 0; jj < tab[ii].size(); jj++)
      cout << tab[ii][jj] << " ";
    cout << endl;
  }
}
