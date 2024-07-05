#include <iostream>

using namespace std;

int lengthOfLastWord(string s) {
    ssize_t ii = s.length() - 1;
    while (ii >= 0 && s[ii] == ' ') {
        ii--;
    }
    ssize_t end = ii;
    while (ii >= 0 && s[ii] != ' ') {
        ii--;
    }

    return end - ii;
}

int main(int argc, char *argv[]) {

    {
        string s = "Hello World";
        cout << lengthOfLastWord(s) << "\n" << flush;
    }
    return 0;
}
