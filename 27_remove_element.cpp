#include <iostream>
#include <vector>

using namespace std;
int removeElement(vector<int> &nums, int val) {
    // kk points to first element after the correct ones
    size_t kk = 0, to_del = 0;

    // nums = [0, 1, 2, 2, 3, 0, 4, 2],  val = 2
    // Edge cases:
    // - all the same and equal to val
    // - empty array
    // - no elements to delete
    while (to_del < nums.size()) {
        while (to_del < nums.size() && nums[to_del] != val) {
            to_del++;
            kk++;
        }

        // Found the first element to delete or end of array
        if (to_del == nums.size()) {
            return kk;
        }

        // Find the next element to swap with
        while (to_del < nums.size() && nums[to_del] == val) {
            to_del++;
        }

        if (to_del == nums.size()) {
            return kk;
        }

        swap(nums[kk], nums[to_del]);

        // Move to the next element with kk
        kk++;
        to_del = kk;
    }

    return kk;
}

int main(int argc, char *argv[]) {
    vector<int> arr{3,2,2,3};
    int val = 3;
    int res = removeElement(arr, val);

    cout << res << std::endl;
    for (const auto & elem: arr) {
        cout << elem << " ";
    }

    // 5, nums = [0,1,4,0,3,_,_,_]
    return 0;
}
