#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    int x;
    cin >> x;
    cout << x / 5 + (x % 5 == 0 ? 0 : 1);
}
