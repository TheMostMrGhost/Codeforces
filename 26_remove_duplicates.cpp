#include <iostream>
#include <vector>

using namespace std;
int removeDuplicates(vector<int> &nums) {
    if (nums.size() <= 1) {
        return nums.size();
    }
    // kk points to first element after the correct ones
    size_t kk = 0, to_del = 1;
    int prev = nums[kk];

    // nums = [0, 1, 2, 2, 3, 0, 4, 2],  val = 2
    // Edge cases:
    // - all the same and equal to val
    // - empty array
    // - no elements to delete
    while (to_del < nums.size() && nums[to_del] != nums[kk]) {
        to_del++;
        kk++;
    }

    // Found the first element to delete or end of array
    if (to_del == nums.size()) {
        return kk + 1;
    }

    prev = nums[kk];
    while (to_del < nums.size()) {
        // Find the next element to swap with
        while (to_del < nums.size() && nums[to_del] <= prev) {
            to_del++;
        } 

        if (to_del == nums.size()) {
            return kk + 1;
        }

        // Move to the kk + 1. Note that nums[kk] == nums[kk + 1]
        kk++;
        swap(nums[kk], nums[to_del]);
        prev = nums[kk];
        to_del++;
    }

    return kk + 1;
}
int main(int argc, char *argv[]) {
    {
        vector<int> arr{1, 1, 2};
        int res = removeDuplicates(arr);

        cout << res << std::endl;

        for (auto const &elem : arr) {
            cout << elem << " ";
        }
        cout << std::endl;
    }
    {
        vector<int> arr{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int res = removeDuplicates(arr);

        cout << res << std::endl;

        for (auto const &elem : arr) {
            cout << elem << " ";
        }
        cout << std::endl;
    }

    {
        vector<int> arr{1, 1, 1};
        int res = removeDuplicates(arr);

        cout << res << std::endl;

        for (auto const &elem : arr) {
            cout << elem << " ";
        }
        cout << std::endl;
    }
    {
        vector<int> arr{1};
        int res = removeDuplicates(arr);

        cout << res << std::endl;

        for (auto const &elem : arr) {
            cout << elem << " ";
        }
        cout << std::endl;
    }

    {
        vector<int> arr{};
        int res = removeDuplicates(arr);

        cout << res << std::endl;

        for (auto const &elem : arr) {
            cout << elem << " ";
        }
        cout << std::endl;
    }
{
        vector<int> arr{0, 1, 2, 3, 4};
        int res = removeDuplicates(arr);

        cout << res << std::endl;

        for (auto const &elem : arr) {
            cout << elem << " ";
        }
        cout << std::endl;
    }


    return 0;
}
