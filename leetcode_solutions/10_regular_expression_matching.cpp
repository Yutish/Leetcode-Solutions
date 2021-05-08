//Problem - Regular Expression Matching

// Solution

int stringMatch(vector<vector<int>> &dp, string &s, string &p, int len_s, int len_p)
{
    if (len_s == 0 && len_p == 0)
        return 1;

    if (len_p == 0)
        return 0;

    if (dp[len_s][len_p] != -1)
        return dp[len_s][len_p];

    if (p[len_p - 1] == '*')
    {
        int res = stringMatch(dp, s, p, len_s, len_p - 2);
        int len_rep = 0;
        while (1)
        {
            if (len_s - len_rep > 0 && (s[len_s - 1 - len_rep] == p[len_p - 2] || p[len_p - 2] == '.'))
                len_rep++;
            else
                break;

            res = res | (stringMatch(dp, s, p, len_s - len_rep, len_p - 2));
        }

        return dp[len_s][len_p] = res;
    }

    if (len_s == 0)
        return dp[len_s][len_p] = 0;

    if (p[len_p - 1] == '.' || s[len_s - 1] == p[len_p - 1])
        return dp[len_s][len_p] = stringMatch(dp, s, p, len_s - 1, len_p - 1);

    return dp[len_s][len_p] = 0;
}

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int len_s = s.length(), len_p = p.length();

        vector<vector<int>> dp(len_s + 1, vector<int>(len_p + 1, -1));

        return stringMatch(dp, s, p, len_s, len_p);
    }
};

//Problem Statement

// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:

// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

// Example 3:

// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".

// Example 4:

// Input: s = "aab", p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

// Example 5:

// Input: s = "mississippi", p = "mis*is*p*."
// Output: false

// Constraints:

// 0 <= s.length <= 20
// 0 <= p.length <= 30
// s contains only lowercase English letters.
// p contains only lowercase English letters, '.', and '*'.
// It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.