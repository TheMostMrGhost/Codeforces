#include <iostream>

using namespace std;

string reverseWords(string s) {
    string res{};
    ssize_t ii = s.length() - 1;

    while (ii >= 0 && s[ii] == ' ') {
        ii--;
    }

    while (ii >= 0) {
        ssize_t end = ii + 1;

        while (ii >= 0 && s[ii] != ' ') {
            ii--;
        }

        if (!res.empty()) {
            res += ' ';
        }

        size_t temp_ii = ii == 0 && s[ii] != ' ' ? 0 : ii + 1;
        res += s.substr(temp_ii, end - temp_ii);

        while (ii >= 0 && s[ii] == ' ') {
            ii--;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    {
        string s = "the sky is blue";
        cout << reverseWords(s) << "|\n" << flush;
    }
    {
        string s = "  hello world  ";
        cout << reverseWords(s) << "|\n";
    }

    {
        string s = " asdasd df f";
        cout << reverseWords(s) << "|\n";
    }

    {
        string s = "a good   example";
        cout << reverseWords(s) << "|\n";
    }
    return 0;
}
