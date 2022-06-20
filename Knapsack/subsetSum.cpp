// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#

#include <bits/stdc++.h>
using namespace std;

// here we choice for each element to select it or not for the sum
// similar to knapsack capacity is given as sum and arr is given with numbers
class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int n = arr.size();

        int dp[n + 1][sum + 1];

        for (int j = 0; j < sum + 1; j++)
        {
            // means number of elements in current arr situation is 0
            // no sum can be generated from empty set
            dp[0][j] = false;
        }
        for (int i = 0; i < n + 1; i++)
        {
            // means sum is zero 0
            // this can always be generated from empty set
            dp[i][0] = true;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    // is current number less than current sum required
                    // then this can included in our set or cannot be
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                {
                    // current number not included
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

int main()
{
    return 0;
}