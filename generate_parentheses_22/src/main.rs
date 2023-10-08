struct Solution;

impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut res : Vec<String> = vec![];

        if n <= 0 {
            return vec!["".to_string()];
        }

        if n == 1 {
            return vec!["()".to_string()];
        }

        for ii in 0..(n - 1) {
            let mut temp = Solution::generate_parenthesis(ii);
            let mut temp2 = Solution::generate_parenthesis(n - ii - 1);
            for s in &mut temp {
                for s2 in &mut temp2 {
                    let contains_target = res.iter().any(|z| *z == s.to_owned() + "(" +  s2 + ")");
                    if !contains_target {
                        res.push(s.to_owned() + "(" +  s2 + ")");
                    }
                    let contains_target = res.iter().any(|z| *z == s.to_owned() + "()" +  s2);

                    if !contains_target {
                        res.push(s.to_owned() + "()" +  s2);
                    }

                    let contains_target = res.iter().any(|z| *z == s.to_owned() +  s2 + "()");

                    if !contains_target {
                        res.push(s.to_owned() +  s2 + "()");
                    }
                }
            }
        }
        return res;
    }
}

#[cfg(test)]
mod test {
    use super::Solution;

    #[test]
    fn no_par() {
        assert_eq!(Solution::generate_parenthesis(0), vec![""]);
    }

    #[test]
    fn single() {
        assert_eq!(Solution::generate_parenthesis(1), vec!["()"]);
    }

    #[test]
    fn two() {
        assert_eq!(Solution::generate_parenthesis(2), vec!["()()", "(())"]);
    }

    #[test]
    fn three() {
        assert_eq!(Solution::generate_parenthesis(4), vec!["()()", "(())"]);
    }

    #[test]
    fn testingo() {
        let test = Solution::generate_parenthesis(6).len().to_string();
        assert_eq!(Solution::generate_parenthesis(5), vec![test]);
    }
}

fn main() {
}

/*
[
"((()()))",
"((())())",
"((()))()",
"(()(()))",
"(())(())",
"()((()))",
"()(()())",
"()()(())",
]

my
[
"()((()))",
"((()))()",
"(()(()))",
"()()(())",
"()(())()",
"((())())",
"((()()))",
"()(()())",
]



*/

