#include <iostream>

using namespace std;

int main (int argc, char *argv[]) {
    int w, h;
    cin >> w >> h;

    if ((w % 2 == 0 || h % 2 == 0) && w * h > 2)
        cout << "Malvika";
    else 
        cout << "Akshat";
}
