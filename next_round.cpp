#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    int n, k, res = 0, last, curr;
    cin >> n >> k;

    int ii = 0;
    cin >> last;

    res += last > 0 ? 1 : 0;

    while (last > 0 && ++ii < k) {
        cin >> curr;

        if (curr > 0 && res <= k ) {
            res++;
            last = curr;
        }
    }

    if (ii < n) {
        cin >> curr;
        while (++ii < n) {
            if (curr != last || curr == 0)
                break;
            else {
                res++;
                last = curr;
            }

            if (ii < n - 1)
                cin >> curr;
        } 
        res += curr == last && last != 0 ? 1 : 0;
    }

    cout << res;
    
}
