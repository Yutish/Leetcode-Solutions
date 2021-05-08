//Problem - Longest Common Prefix

// Solution

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int len = strs.size();
        if (len == 0)
            return "";
        if (len == 1)
            return strs[0];

        sort(strs.begin(), strs.end());

        int i = 0;
        string smallest = strs[0], largest = strs[len - 1];

        while (i < smallest.length() && smallest[i] == largest[i])
            i++;

        return smallest.substr(0, i);
    }
};

//Problem Statement

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lower-case English letters.