#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums) {
    size_t beg = 1, end = 1;
    int prev = nums[0], count = 1;

    while (end < nums.size()) {
        nums[beg] = nums[end];

        if (nums[end] == prev) {
            if (count < 2) {
                beg++;
            }
            end++;
            count++;
        } else {
            prev = nums[end];
            count = 1;
            beg++;
            end++;
        }
    }

    return beg;
}

int main(int argc, char *argv[]) {

    {
        int nums[] = {1, 1, 1, 2, 2, 3};
        vector<int> nums_v(nums, nums + sizeof(nums) / sizeof(int));
        int k = removeDuplicates(nums_v);
        cout << k << endl;
        for (int i = 0; i < k; i++) {
            cout << nums_v[i] << " ";
        }
        cout << endl;
    }
    {
        int nums[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
        vector<int> nums_v(nums, nums + sizeof(nums) / sizeof(int));
        int k = removeDuplicates(nums_v);
        cout << k << endl;
        for (int i = 0; i < k; i++) {
            cout << nums_v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
