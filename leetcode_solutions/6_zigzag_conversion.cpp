//Problem - ZigZag Conversion

// Solution

class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (s.length() < 3 || numRows == 1)
        {
            return s;
        }

        vector<string> vec(numRows);
        int j = 0, i = 0;
        string res = "";

        while (i < s.length())
        {

            while (j < numRows && i < s.length())
            {
                vec[j++] += s[i++];
            }

            if (j == numRows)
                j = numRows - 2;

            while (j >= 0 && i < s.length())
            {
                vec[j--] += s[i++];
            }

            if (j == -1)
                j = 1;
        }

        for (int i = 0; i < vec.size(); i++)
        {

            res += vec[i];
        }
        return res;
    }
};

//Problem Statement

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"

// Constraints:

// 1 <= s.length <= 1000
// s consists of English letters (lower-case and upper-case), ',' and '.'.
// 1 <= numRows <= 1000