// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // if number can be divided into two subsets of equal sum lets say 's'
        // s+s = 2s -> equal to sum of given array
        // so division is only possible is sum of array is even

        int sum = 0;
        for (int num : nums)
            sum += num;

        // if sum is odd, subset of equal sum not possible, return false
        if (sum & 1)
            return false;

        // now after this the case reduces to subset sum
        // we need to find if subset of sum = s (sumArr/2) exists or not
        // if exists then then the other half will also exists to make is 2s that is sumArr;

        return subsetSum(nums, sum / 2, nums.size());
    }

    bool subsetSum(vector<int> &nums, int sum, int n)
    {

        bool dp[n + 1][sum + 1];

        // means number of elements in current arr situation is 0
        // no sum can be generated from empty set
        for (int k = 0; k < sum + 1; k++)
            dp[0][k] = false;

        // means sum is zero 0
        // this can always be generated from empty set
        for (int k = 0; k < n + 1; k++)
            dp[k][0] = true;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {

                // is current number less than current sum required
                // then this can included in our set or cannot be
                if (nums[i - 1] <= j)
                    dp[i][j] = (dp[i - 1][j - nums[i - 1]] || dp[i - 1][j]);

                // current number not included
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};

int main()
{

    return 0;
}