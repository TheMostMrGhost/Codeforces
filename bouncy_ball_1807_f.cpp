#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

enum direction {
  UR = 0,
  UL = 1,
  DL = 2,
  DR = 3
};

direction decode(string direction);
int solve(int n, int m, int i1, int j1, int i2, int j2, direction dir);
bool on_path(int i1, int j1, int i2, int j2, int i_next, int j_next, int coef);

int main() {
  int t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) {
    int n, m, i1, j1, i2, j2;
    string dir;

    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> dir;
    cout << solve(n, m, i1, j1, i2, j2, decode(dir)) << "\n";
  }
}

int solve(int n, int m, int i1, int j1, int i2, int j2,  direction dir) {
  if (i1 == i2 && j1 == j2)
    return 0;

  bool been_in_start = false;

  int i_orginal = i1, j_original = j1; // i1, j1 at the start
  int i_next, j_next; // Coordinates of the next bounce
  direction current_direction = dir;
  vector<pair<int, int>> coef{make_pair(1, 1), make_pair(-1, 1), make_pair(-1, -1), make_pair(1, -1)};
  int current_bounces = 0;

  while (true) {
    int moves;
    // TODO Coordinates system may be unorthodox
    direction next_dir;
    if (current_direction == UR) {
      moves = min(n - i1, m - j1); 
      // Od góry i UR -> DR, od boku i UR to UL + róg
      if (n - i1 == m - j1)
        next_dir = DL;
      else
        next_dir = n - i1 < m - j1 ? UL : DR;
    }
    else if (current_direction == UL) {
      moves = min(i1, m - j1); 
      // Od góry i UL -> DL, od boku i UR to UL + róg to DR
      if (i1 == m - j1)
        next_dir = DR;
      else
        next_dir = i1 < m - j1 ? DL : UR;
    }
    else if (current_direction == DR) {
      moves = min(n - i1, j1); 
      if (n - i1 == j1)
        next_dir = UL;
      else
        next_dir = n - i1 < j1 ? DL : UR;
    }
    else {
      moves = min(i1, j1); 
      if (i1 == j1)
        next_dir = DL;
      else
        next_dir = i1 < j1 ? UL : DR;
    }

    cout << moves  << "\n";
    i_next = i1 + coef[dir].first * moves;
    j_next = j1 + coef[dir].second * moves;

    // Colinear and in the same direction
    if (on_path(i1, j1, i2, j2, i_next, j_next, coef[dir].first))
      return current_bounces;

    if (on_path(i1, j1, i2, j2, i_orginal, j_original, coef[dir].first)) { // Checking wether we were in the starting point twice
      if (been_in_start)
        return -1;

      been_in_start = true;
    }

    i1 = i_next;
    j1 = j_next;
    cout << i1 << " " << j1 << "\n";
    dir = next_dir;


    // TODO break when second time in starting position
  }

}


direction decode(string direction) {
  if (direction == "DL")
    return DL;
  if (direction == "UL")
    return UL;
  if (direction == "DR")
    return DR;
  return UR;

}

bool on_path(int i1, int j1, int i2, int j2, int i_next, int j_next, int coef) {
  return (j_next - j1)  * (i2 - i1) == (j2 - j1) * (i_next - i1) && coef * (i2 - i1) > 0;
}

