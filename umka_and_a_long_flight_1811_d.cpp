#include <iostream>

using namespace std;

bool solve(int n, int w, int h);
void preprocess();

/* Note that such square can be covered by n + 1 Fibonacci squares exactly 
 * when those are all Fibonacci numbers from 0 to n inclusive.
 * This is because
 * F_0 + F_1 + ... + F_{n - 1} + F_n = F_{n + 2} - 1
 * and 
 * F_0 ^ 2 + F_1 ^2 + ... + F_{n - 1} ^2 + F_n ^2 = F_n * F_{n + 1}
 */
constexpr int max_size = 44 + 1 + 1;
int *fibb_size;

int main (int argc, char *argv[]) {
  fibb_size = new int[max_size];
  preprocess();

  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, x, y;
    cin >> n >> x >> y;

    if (solve(n, y, x)) // FIXME
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  


  delete[] fibb_size;
}

bool solve(int n, int x, int y) {
  // Simplest case, always possible
  if (n == 1)
    return true;

  // Recursive step, we try to fit largest possible Fibonacci square
  // which is n x n
  int box_h = fibb_size[n], box_w = fibb_size[n + 1];
  // We assume that width > height
  int square_size = fibb_size[n];

  // cout << box_w << " " << box_h << endl;
  if (x > box_w - box_h && x <= box_h)
    return false;

  if (x > box_h) {
    x -= box_h;
  } 

  return solve(n - 1, y, x);
}

void preprocess() {
  fibb_size[0] = 1;
  fibb_size[1] = 1;

  for (int ii = 2; ii < max_size; ii++)
    fibb_size[ii] = fibb_size[ii - 1] + fibb_size[ii - 2];
}
