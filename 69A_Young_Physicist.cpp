#include <iostream>
#include <tuple>

using namespace std;
using Vec = tuple < int, int, int >;

Vec operator+(Vec v1,Vec v2) {
    Vec res{
        get<0>(v1) + get<0>(v2),
        get<1>(v1) + get<1>(v2),
        get<2>(v1) + get<2>(v2)
    };

    return res;
}

int main (int argc, char *argv[]) {
    int n;
    cin >> n;

    Vec res{};

    for (int ii = 0; ii < n; ii++) {
        int x, y, z;
        cin >> x >> y >> z;
        Vec temp{x, y, z};

        res = res + temp;
    }

    if (get< 0 >(res) == 0 && get< 1 >(res) == 0 && get< 2 >(res) == 0)
        cout << "YES";
    else 
        cout << "NO";
}
