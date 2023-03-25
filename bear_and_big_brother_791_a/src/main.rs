use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Wrong format");
    let mut numbers = input.trim().split(' ');

    // Parse the first number
    let a: u32 = numbers.next().unwrap().parse().unwrap();
    // Parse the second number
    let b: u32 = numbers.next().unwrap().parse().unwrap();

    let res = years(a, b);
    print!("{res}\n");
}

fn years(mut a: u32, mut b: u32) -> u32 {
    let mut ii = 0;

    while a <= b {
        a *= 3;
        b *= 2;
        ii += 1;
    };

    ii
}
