#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> &nums) {
    int max_jump = nums[0];
    size_t prev_pos = 0, curr_pos = 0, jumps = 0;

    while (curr_pos < nums.size() - 1) {
        jumps++;
        size_t next_pos = curr_pos;

        for (size_t ii = prev_pos; ii <= curr_pos; ii++) {
            next_pos = max(next_pos, ii + nums[ii]);
        }

        prev_pos = curr_pos;
        curr_pos = next_pos;
    }

    return jumps;
}

int main(int argc, char *argv[]) {

    {
        vector<int> nums = {2, 3, 1, 1, 4};
        cout << jump(nums) << endl;
    }

    {
        vector<int> nums = {2, 3, 0, 1, 4};
        cout << jump(nums) << endl;
    }

    return 0;
}
