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
        let arr: Vec<usize> = input.trim().split_whitespace().map(|s| s.parse().unwrap()).collect();

        let res = solve(&arr);
        print!("{res}\n");
        input.clear();
    }
}

fn solve(arr: &Vec<usize>) -> usize {
    // let max = 2 * 100000;
    let n = arr.len();
    let mut zeros: usize = 0;
    let mut one: bool = false;
    let mut greater_than_one: bool = false;

    for ii in 0..n {
        if arr[ii] == 0 {
            zeros += 1;
        }
        else if arr[ii] == 1 {
            one = true;
        }
        else {
            greater_than_one = true;
        }
    }

    if zeros < (n + 1) / 2 + 1 {
        return 0;
    }

    if !one {
        return 1;
    }

    if !greater_than_one {
        return 2;
    }
    1
}
