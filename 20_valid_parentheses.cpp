//Problem - Valid Parentheses

// Solution

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;

        if (s[0] == ')' || s[0] == '}' || s[0] == ']')
            return false;

        stk.push(s[0]);

        int i = 1;
        while (i < s.length())
        {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            else if ((s[i] == ')' && !stk.empty() && stk.top() == '(') ||
                     (s[i] == '}' && !stk.empty() && stk.top() == '{') ||
                     (s[i] == ']' && !stk.empty() && stk.top() == '['))
            {
                stk.pop();
            }
            else
            {
                return false;
            }

            i++;
        }

        return stk.empty();
    }
};

//Problem Statement

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
// Example 4:

// Input: s = "([)]"
// Output: false
// Example 5:

// Input: s = "{[]}"
// Output: true

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.