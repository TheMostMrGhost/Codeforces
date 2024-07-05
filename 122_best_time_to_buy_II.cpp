#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
    int res = 0;

    for (size_t ii = 1; ii < prices.size(); ii++) {
        if (prices[ii] > prices[ii - 1]) {
            res += prices[ii] - prices[ii - 1];
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    {
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        cout << maxProfit(prices) << endl;  // 5
    }
    {
        vector<int> prices = {1, 2, 3, 4, 5};
        cout << maxProfit(prices) << endl;  // 5
    }
    {
        vector<int> prices = {7, 6, 4, 3, 1};
        cout << maxProfit(prices) << endl;  // 0
    }
    return 0;
}
