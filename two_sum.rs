impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for (ii, &elem1) in nums.iter().enumerate() {
            for (jj, &elem2) in nums.iter().enumerate().skip(ii + 1) {
                if elem1 + elem2 == target {
                    return vec![ii as i32, jj as i32];
                }
            }
        }
        return vec![0, 0];
    }
}
