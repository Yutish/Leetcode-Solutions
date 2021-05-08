//Problem - Longest Palindromic Substring

// Solution

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();

        vector<vector<bool>> vec(n, vector<bool>(n, 0));

        int maxLength = 1; // if length 1 substrings = palindromes

        for (int i = 0; i < n; ++i)
            vec[i][i] = true;

        int start = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                vec[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        for (int k = 3; k <= n; ++k)
        {

            for (int i = 0; i < n - k + 1; ++i)
            {

                int j = i + k - 1;

                if (vec[i + 1][j - 1] && s[i] == s[j])
                {
                    vec[i][j] = true;

                    if (k > maxLength)
                    {
                        start = i;
                        maxLength = k;
                    }
                }
            }
        }

        string res = "";
        for (int i = start; i <= start + maxLength - 1; ++i)
            res += s[i];

        return res;
    }
};

//Problem Statement

// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// Example 2:

// Input: s = "cbbd"
// Output: "bb"

// Example 3:

// Input: s = "a"
// Output: "a"

// Example 4:

// Input: s = "ac"
// Output: "a"

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters (lower-case and/or upper-case)