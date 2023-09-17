fn convert(character: char) -> i32 {
    return match character {
        'M' => 1000,
        'D' => 500,
        'C' => 100,
        'L' => 50,
        'X' => 10,
        'V' => 5,
        'I' => 1,
        _ => 0,
    };
}
fn roman_to_int(roman: &str) -> i32 {
    let roman: Vec<char> = roman.chars().collect();
    let mut res: i32 = 0;

    let mut ii = 0;
    while ii < (roman.len() - 1) {
        let a = convert(roman[ii]);
        let b = convert(roman[ii + 1]);
        if a < b {
            res += b - a;
            ii += 2;
        } else {
            res += a;
            ii += 1;
        }
    }

    if ii < roman.len() {
        res += convert(roman[ii]);
    }
    return res;
}
fn main() {
    let res = roman_to_int("MMDD");
    print!("{res}");
}
