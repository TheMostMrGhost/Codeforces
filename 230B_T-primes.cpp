#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
constexpr int MAX_SIZE = 10000000;

// Checks if number is a perfect square of prime number
bool check(int a, vector<int> *primes);

// Computes primes in range [2, size] using Erastotenes sieve
vector<int> *sieve(int size);

int main(int argc, char *argv[]) {

  int num;
  vector<int> *vec = sieve(MAX_SIZE);

  cin >> num;

  for (int ii = 0; ii < num; ii++) {
    int temp;
    cin >> temp;

    if (check(temp, vec))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}

vector<int> *sieve(int size) {

  vector<int> *res = new vector<int>();
  vector<bool> primes(size, true);

  for (int ii = 0; ii < size - 2; ii++) { // TODO Check for off by 1 error
    if (primes[ii]) {
      int prime = ii + 2;
      int kk = 2;

      while (kk * prime <= size)
        primes[(kk++) * prime - 2] = false;
    }
  }

  // Rewriting array to contain just primes
  for (int ii = 0; ii < size - 2; ii++) {
    if (primes[ii])
      res->push_back(ii + 2);
  }

  return res;
}

bool check(int a, vector<int> *primes) {
  if (a < 2)
    return false;

  int beg = 1, end = a, mid = beg + (end - beg) / 2;

  while (beg < end) {
    if (mid * mid < a)
      beg = mid + 1; // TODO off by 1
    else
      end = mid;

    mid = beg + (end - beg) / 2;
  }

  cout << mid;
  return mid * mid == a && binary_search(primes->begin(), primes->end(), mid);
}
