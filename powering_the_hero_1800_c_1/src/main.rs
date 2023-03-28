use std::collections::BinaryHeap;
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
        let arr: Vec<u64> = input.trim().split_whitespace().map(|s| s.parse().unwrap()).collect();

        let res = solve(&arr);
        print!("{res}\n");
        input.clear();
    }
}

fn solve(arr: &Vec<u64>) -> u64 {
    let mut bonus_deck = BinaryHeap::<u64>::new();
    let mut res: u64 = 0;

    for elem in arr {
        if *elem == 0 && !bonus_deck.is_empty() {
            res += bonus_deck.pop().unwrap();
        }
        else if *elem > 0{
            bonus_deck.push(*elem);
        }
    }
    res
}
