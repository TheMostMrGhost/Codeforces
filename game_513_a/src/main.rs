use std::io;

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input).expect("Wrong format");
    let mut numbers = input.trim().split(' ');

    let mut arr = [0; 4];

    for ii in 0..4 {
        arr[ii] = numbers.next().unwrap().parse().unwrap();
    }

    let n1 = arr[0];
    let n2 = arr[1];

    let res = who_wins(n1, n2);
    print!("{}", res);
}

fn who_wins(n1: u32, n2: u32) -> String {
    if n1 > n2 {
        return String::from("First\n");
    }
    String::from("Second\n")
}
