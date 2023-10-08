struct Solution;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        // create stack
        // on opening parenthesis push on the stack
        // on closing pop
        let mut parentheses : Vec<char> = vec![];

        for cc in s.chars() {
            match cc {
                '(' | '{' | '[' => {
                    parentheses.push(cc);
                }

                ')' => {
                    let top = parentheses.pop();
                    match top {
                        Some(top) => {
                            if top != '(' {
                                return false;
                            }
                        }
                        None => { return false; }
                    }
                }

                ']' => {
                    let top = parentheses.pop();
                    match top {
                        Some(top) => {
                            if top != '[' {
                                return false;
                            }
                        }
                        None => { return false; }
                    }
                }

                '}' => {
                    let top = parentheses.pop();
                    match top {
                        Some(top) => {
                            if top != '{' {
                                return false;
                            }
                        }
                        None => { return false; }
                    }
                }
                _ => {}
            }
        }
        return parentheses.is_empty();
    }
}

#[cfg(test)]
mod test {
    use super::Solution;

    #[test]
    fn empty() {
        let a = String::from("");
        assert!(Solution::is_valid(a));
    }

    #[test]
    fn no_parentheses() {
        let a = String::from("ahnssyqjnk728nssja");
        assert!(Solution::is_valid(a));
    }

    #[test]
    fn simple_sequentioal() {
        let a = String::from("(){}[]");
        assert!(Solution::is_valid(a));
    }

    #[test]
    fn incorrect_simple() {
        let a = String::from("(]");
        assert!(!Solution::is_valid(a));
    }

    #[test]
    fn single_closing() {
        let a = String::from("]");
        assert!(!Solution::is_valid(a));
    }
}

fn main() {
}
