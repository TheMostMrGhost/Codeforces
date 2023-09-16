use std::io;
fn is_palindrome(x: i32) -> bool {
    let mut power = 10;
    let mut rev = 0;

    if x < 0 {
        return false;
    }
    if x >= 0 && x < 10 {
        return true;
    }
    while power <= x && power <= 100000000 {
        rev *= 10;
        rev += (x % power - x % (power / 10)) / (power / 10);
        power *= 10;
    }
    if power <= 1000000000 {
    rev *= 10;
    rev += (x % power - x % (power / 10)) / (power / 10);
    }
    if x > 1000000000 {
    rev *= 10;
    rev += x / power;
    }
    return rev - x == 0;

}
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("input expected");
    let x: i32 = input.trim().parse().expect("Failed to parse to integer");
    // print!("{x}");
    let res = is_palindrome(x);
    print!("{res}");
}
