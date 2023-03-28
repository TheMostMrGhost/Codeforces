// use std::collections::BinaryHeap;
use std::collections::BTreeSet;
use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let t: u32 = input.trim().parse().unwrap();
    input.clear();

    for _ii in 0..t {
        io::stdin().read_line(&mut input).unwrap();
        let n: usize = input.trim().parse().unwrap();
        input.clear();

        io::stdin().read_line(&mut input).unwrap();
        let arr: Vec<i64> = input.trim().split_whitespace().map(|s| s.parse().unwrap()).collect();

        let tuple = solve(&arr);

        if tuple.0 < tuple.1 {
            print!("{} {}\n", tuple.0 + 1, tuple.1 + 1);
        }
        else {
            print!("-1\n");
        }

        input.clear();
    }
}

fn solve(arr: &Vec<i64>) -> (usize, usize) {
    // Preprocessing
    let n = arr.len() as i64;
    let mut values : BTreeSet::<i64> = (1..=n).collect();

    let mut left = 0usize;
    let mut right = arr.len() - 1;

    while left < right {

        if arr[left] == *values.first().unwrap() {
            values.pop_first();
            left += 1;
        }
        else if arr[left] == *values.last().unwrap() {
            values.pop_last();
            left += 1;
        }
        else if arr[right] == *values.first().unwrap() {
            values.pop_first();
            right -= 1;
        }
        else if arr[right] == *values.last().unwrap() {
            values.pop_last();
            right -= 1;
        }
        else { break; }

    }

    (left, right)
}
