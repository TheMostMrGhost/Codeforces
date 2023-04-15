#include <iostream>

using namespace std;

long long total_cost(long long x, long long y);

int main (int argc, char *argv[]) {
  int t;
  cin >> t;

  for (int ii = 0; ii < t; ii++) {
    long long x, y;
    cin >> x >> y;
    cout << total_cost(x, y) << "\n";
  }
}

long long total_cost(long long x, long long y) {
  if (x > y) {
    long long c = x;
    x = y;
    y = c;
  }

  long long cost_x = 0;
  long long cost_y = 0;
  long long mincost = 20000000000;

  for (long long ymax = 1; ymax <= y; ymax++) {
    cost_x = ymax > x ? 1 : (x / ymax + (x % ymax == 0 ? 0 : 1));
    cost_y = y / ymax + (y % ymax == 0 ? 0 : 1);

    long long cost = cost_x + cost_y + ymax - 1;

    if (cost < mincost)
      mincost = cost;
    else if (cost > mincost + 1) 
      break;
  }

  return mincost;
}

