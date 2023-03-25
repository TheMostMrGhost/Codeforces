#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    int n, m;
    cin >> m >> n;

    if (m % 2 == 0 || n % 2 == 0)
        cout << m * n / 2;
    else 
        cout << (m - 1) * n / 2 + (n - 1) / 2;
}
