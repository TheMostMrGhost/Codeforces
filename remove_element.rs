pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
    let mut indices = vec![];
    let mut diff : i32 = 0;
    for (ii, elem) in nums.iter().enumerate() {
        if *elem == val {
            indices.push(ii);
        }
        else {
            diff += 1;
        }
    }
    let mut del = 0;
    for ii in indices {
        nums.remove(ii - del);

        del += 1;
    }

    return diff
}

fn main() {
    let mut nums = vec![0, 1, 2, 2, 3, 0, 4, 2];
    let val = 2;
    let res = remove_element(&mut nums, val);
    print!("{res}");
}
