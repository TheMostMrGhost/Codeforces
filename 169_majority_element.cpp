#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> &nums) {
    int count = 0, majority_elem = 0;

    for (size_t ii = 0; ii < nums.size(); ii++) {
        if (count == 0 || nums[ii] == majority_elem) {
            majority_elem = nums[ii];
            count++;
        } else {
            count--;
        }
    }

    return majority_elem;
}

int main(int argc, char *argv[]) {

    {
        int nums[] = {3, 2, 3};
        vector<int> nums_v(nums, nums + sizeof(nums) / sizeof(int));
        int k = majorityElement(nums_v);
        cout << k << endl;
    }

    {
        int nums[] = {2, 2, 1, 1, 1, 2, 2};
        vector<int> nums_v(nums, nums + sizeof(nums) / sizeof(int));
        int k = majorityElement(nums_v);
        cout << k << endl;
    }
    return 0;
}
