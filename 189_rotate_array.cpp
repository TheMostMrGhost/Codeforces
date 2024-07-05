#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &nums, int k) {
    k = k % nums.size();

    if (nums.size() == 0 || k == 0) {
        return;
    }

    vector<int> nums_copy{nums.end() - k, nums.end()};

    for (size_t ii = nums.size() - 1; ii >= k; ii--) {
        nums[ii] = nums[ii - k];
    }

    for (size_t ii = 0; ii < nums_copy.size(); ii++) {
        nums[ii] = nums_copy[ii];
    }
}

int main(int argc, char *argv[]) {

    {
        int nums[] = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;
        vector<int> nums_v(nums, nums + sizeof(nums) / sizeof(int));
        rotate(nums_v, k);
        for (int i = 0; i < nums_v.size(); i++) {
            cout << nums_v[i] << " ";
        }
        cout << endl;
    }
    {
        int nums[] = {-1,-100,3,99};
        int k = 2;
        vector<int> nums_v(nums, nums + sizeof(nums) / sizeof(int));
        rotate(nums_v, k);
        for (int i = 0; i < nums_v.size(); i++) {
            cout << nums_v[i] << " ";
        }
        cout << endl;
    }

    {
        int nums[] = {1};
        int k = 0;
        vector<int> nums_v(nums, nums + sizeof(nums) / sizeof(int));
        rotate(nums_v, k);
        for (int i = 0; i < nums_v.size(); i++) {
            cout << nums_v[i] << " ";
        }
        cout << endl;
    }
    {
        int nums[] = {1, 2};
        int k = 0;
        vector<int> nums_v(nums, nums + sizeof(nums) / sizeof(int));
        rotate(nums_v, k);
        for (int i = 0; i < nums_v.size(); i++) {
            cout << nums_v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
