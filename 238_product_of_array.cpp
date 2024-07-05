#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
    int prod = 1;
    int zeros = 0;
    vector<int> res(nums.size());

    for (int const elem : nums) {
        if (elem == 0) {
            zeros++;
        } else {
            prod *= elem;
        }
    }

    for (size_t ii = 0; ii < res.size(); ii++) {
        if (zeros > 1) {
            res[ii] = 0;
            continue;
        } else if (zeros == 1) {
            if (nums[ii] == 0) {
                res[ii] = prod;
            } else {
                res[ii] = 0;
            }
            continue;
        } else {
            res[ii] = prod / nums[ii];
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

    {

        vector<int> nums = {1, 2, 3, 4};
        vector<int> res = productExceptSelf(nums);
        for (int const elem : res) {
            cout << elem << " ";
        }
        cout << endl;
    }
    {
        vector<int> nums = {-1, 1, 0, -3, 3};
        vector<int> res = productExceptSelf(nums);
        for (int const elem : res) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
