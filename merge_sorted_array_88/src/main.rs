struct Solution {}

impl Solution {

    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        if n == 0 {
            return;
        }

        let mut ii1 = m as usize;
        let mut ii2 = n as usize;
        let mut idx: usize = nums1.len();

        while idx > 0 {
            if ii2 == 0 {
                break;
            }

            if ii1 > 0 && nums1[ii1 - 1] > nums2[ii2 - 1] {
                nums1[idx - 1] = nums1[ii1 - 1];

                if ii1 > 0 {
                    ii1 -= 1;
                }
            } else {
                nums1[idx - 1] = nums2[ii2 - 1];

                if ii2 > 0 {
                    ii2 -= 1;
                }
            }

            idx -= 1;
        }
    }
}

fn main() {
    let mut nums1 = vec![1, 2, 3, 0, 0, 0];
    let m = 3;
    let mut nums2 = vec![2, 5, 6];
    let n = 3;
    let expected = vec![1, 2, 2, 3, 5, 6];

    Solution::merge(&mut nums1, m, &mut nums2, n);
    assert_eq!(nums1, expected);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example1() {
        let mut nums1 = vec![1, 2, 3, 0, 0, 0];
        let m = 3;
        let mut nums2 = vec![2, 5, 6];
        let n = 3;
        let expected = vec![1, 2, 2, 3, 5, 6];

        Solution::merge(&mut nums1, m, &mut nums2, n);
        assert_eq!(nums1, expected);
    }

    #[test]
    fn example2() {
        let mut nums1 = vec![1];
        let m = 1;
        let mut nums2 = vec![];
        let n = 0;
        let expected = vec![1];

        Solution::merge(&mut nums1, m, &mut nums2, n);
        assert_eq!(nums1, expected);
    }

    #[test]
    fn example3() {
        let mut nums1 = vec![0];
        let m = 0;
        let mut nums2 = vec![1];
        let n = 1;
        let expected = vec![1];

        Solution::merge(&mut nums1, m, &mut nums2, n);
        assert_eq!(nums1, expected);
    }
}
