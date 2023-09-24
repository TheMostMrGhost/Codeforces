struct Solution;

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut prefix = String::new();
        let mut length = strs.get(0).expect("REASON").len();

        println!("{length}");
        for elem in &strs {
            length = if length > elem.len() { elem.len() } else { length };
        }

        for ii in 0..length {
            let current_char = strs[0].chars().nth(ii).expect("Failed");
            for elem in &strs {
                if let Some(char_to_compare) = elem.chars().nth(ii) {
                    if char_to_compare != current_char {
                        return prefix;
                    }
                } else {
                    return prefix;
                }
            }
            prefix.push(current_char);
        }

        prefix
    }
}

#[cfg(test)]
mod test {
    use super::Solution;

    #[test]
    fn name() {
        let strs = vec!["dog".to_string(), "racecar".to_string(), "car".to_string()];
        let result = Solution::longest_common_prefix(strs);
        assert_eq!(result, "".to_string());
    }

    #[test]
    fn test_longest_common_prefix() {
        let strs = vec!["flower".to_string(), "flow".to_string(), "flight".to_string()];
        let result = Solution::longest_common_prefix(strs);
        assert_eq!(result, "fl".to_string());
    }

    #[test]
    fn empty_string() {
        let strs = vec!["".to_string()];
        let result = Solution::longest_common_prefix(strs);
        assert_eq!(result, "".to_string());
    }

    #[test]
    fn single_char() {
        let strs = vec!["a".to_string()];
        let result = Solution::longest_common_prefix(strs);
        assert_eq!(result, "a".to_string());
    }
}
fn main() {
}
