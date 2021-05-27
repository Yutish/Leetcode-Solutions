//Problem - 3Sum

// Solution

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &A)
    {
        sort(A.begin(), A.end());

        vector<vector<int>> res;
        int n = A.size();

        vector<int> ar;

        for (int i = 0; i < n && A[i] <= 0;)
        {
            int sum = -A[i];

            for (int j = i + 1, k = n - 1; j < k;)
            {

                if (A[j] + A[k] == sum)
                {

                    res.push_back({A[i], A[j], A[k]});

                    j++;

                    ar.clear();

                    while (j < k && (A[j] == A[j - 1]))
                        j++;
                }
                else if (A[j] + A[k] < sum)
                    j++;
                else
                    k--;
            }
            i++;
            while (i < n and A[i] == A[i - 1])
                i++;
        }
        return res;
    }
};

//Problem Statement

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Example 2:

// Input: nums = []
// Output: []

// Example 3:

// Input: nums = [0]
// Output: []
 

// Constraints:

// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105