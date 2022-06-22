// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

#include <bits/stdc++.h>
using namespace std;

// TLE
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n)
    {
        // base case
        if (n == 0 || W == 0)
            return 0;

        if (wt[n - 1] <= W)
        {
            // two choices include it or exclude it
            int inProfit = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1);
            int exProfit = knapSack(W, wt, val, n - 1);

            return max(inProfit, exProfit);
        }
        else
        {
            // cannot be included
            return knapSack(W, wt, val, n - 1);
        }
    }
};

// Acceeption recursion with memoization
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int dp[1002][1002];

    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }

    int knapSack(int W, int wt[], int val[], int n)
    {
        // base case
        if (n == 0 || W == 0)
            return 0;

        if (dp[n][W] != -1)
        {
            return dp[n][W];
        }

        if (wt[n - 1] <= W)
        {
            // two choices include it or exclude it
            int inProfit = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1);
            int exProfit = knapSack(W, wt, val, n - 1);

            return dp[n][W] = max(inProfit, exProfit);
        }
        else
        {
            // cannot be included
            return dp[n][W] = knapSack(W, wt, val, n - 1);
        }
    }
};

// Acception Top-Down DP solution
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.

    int knapSack(int W, int wt[], int val[], int n)
    {
        int dp[n + 1][W + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < W + 1; j++)
            {
                // base case to intialization
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (wt[i - 1] <= j)
                {
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }
};

int main()
{
    return 0;
}