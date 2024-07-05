#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums) {
    int max_jump = nums[0];

    for (int ii = 1; ii < nums.size(); ii++) {
        if (max_jump < ii) {
            return false;
        }
        max_jump = max(max_jump, ii + nums[ii]);
    }

    return true;
}

int main(int argc, char *argv[]) {

    {
        vector<int> nums = {2, 3, 1, 1, 4};
        cout << canJump(nums) << endl;
    }

    {
        vector<int> nums = {3, 2, 1, 0, 4};
        cout << canJump(nums) << endl;
    }

    return 0;
}
