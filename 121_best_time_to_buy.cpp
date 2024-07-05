#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
    int res = 0;
    size_t beg = 0, end = 1;

    while (end < prices.size()) {
        if (prices[end] > prices[beg]) {
            res = max(res, prices[end] - prices[beg]);
        } else {
            beg = end;
        }
        end++;
    }

    return res;
}

int main(int argc, char *argv[]) {

    {
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        cout << maxProfit(prices) << endl;  // 5
    }

    {
        vector<int> prices = {7, 6, 4, 3, 1};
        cout << maxProfit(prices) << endl;  // 0
    }
    return 0;
}
