//Problem - Generate Parentheses

// Solution

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {

        vector<string> res;

        if (n == 0)
        {
            res.push_back("");
        }
        else
        {
            for (int c = 0; c < n; ++c)

                for (auto left : generateParenthesis(c))

                    for (auto right : generateParenthesis(n - 1 - c))

                        res.push_back("(" + left + ")" + right);
        }
        return res;
    }
};

//Problem Statement

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

// Constraints:

// 1 <= n <= 8