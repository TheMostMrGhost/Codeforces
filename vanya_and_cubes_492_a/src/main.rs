use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Wrong");
    let mut numbers = input.trim().split(' ');
    let n: i32 = numbers.next().unwrap().parse().unwrap();

    let max_pir = max_piramid(n);
    println!("{max_pir}");
}

fn max_piramid(mut n: i32) -> i32 {
    let mut ii = 1;

    if n == 1 {
        return 1;
    }
    while next_level(ii) <= n {
        n -= next_level(ii);
        ii += 1;
    }
    ii - 1
}

fn next_level(height: i32) -> i32 {
    height * (height + 1) / 2
}
