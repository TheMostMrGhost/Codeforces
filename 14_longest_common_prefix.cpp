#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    string res = "";
    size_t ii = 0;

    while (true) {
        for (auto const &elem : strs) {
            if (ii >= elem.length() || elem[ii] != strs.at(0)[ii]) {
                return res;
            }
        }

        res += strs.at(0)[ii];
        ii++;
    }
}

int main(int argc, char *argv[]) {

    {
        vector<string> strs{"flower", "flow", "flight"};
        cout << longestCommonPrefix(strs) << "\n" << flush;
    }
    {
        vector<string> strs{"dog", "racecar", "car"};
        cout << longestCommonPrefix(strs) << "\n" << flush;
    }
    {
        vector<string> strs{"racecar", "racecar"};
        cout << longestCommonPrefix(strs) << "\n" << flush;
    }

    return 0;
}
