#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int hIndex(vector<int> &citations) {
    std::make_heap(citations.begin(), citations.end());
    int hh = 0;

    while (!citations.empty() && citations.front() > hh) {
        std::pop_heap(citations.begin(), citations.end());
        citations.pop_back();
        hh++;
    }

    return hh;
}

int main(int argc, char *argv[]) {

    {
        vector<int> citations = {3, 0, 6, 1, 5};
        cout << hIndex(citations) << endl;
    }
    {
        vector<int> citations = {1, 3, 1};
        cout << hIndex(citations) << endl;
    }
    return 0;
}
