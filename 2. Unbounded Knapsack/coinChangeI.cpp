// https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

// greedy approach not work
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end(), greater<int>());
        int cnt = 0;
        for (int i : coins)
        {
            if (i <= amount)
            {
                cnt += amount / i;
                amount %= i;
                cout << i << " " << amount << " " << cnt;
            }
        }

        if (amount == 0)
            return cnt;

        return -1;
    }
};

// dp solution
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        int amt = amount;
        vector<int> dp(amt + 1, amt + 1);
        dp[0] = 0;
        for (int i = 0; i <= amt; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                int bal = i - coins[j];
                if (bal == 0)
                {
                    dp[i] = 1;
                    continue;
                }
                else if (bal > 0)
                {
                    dp[i] = min(dp[i], 1 + dp[bal]);
                }
            }
        }
        if (dp[amt] == amt + 1)
            return -1;
        return dp[amt];
    }
};

// kanpsack solution
class Solution
{
public:
    int coinChange(vector<int> &coins, int amt)
    {
        int n = coins.size();
        int dp[n + 1][amt + 1];

        // number of coins is zero, so no sum can be build up
        for (int j = 0; j < amt + 1; j++)
            dp[0][j] = INT_MAX - 1; // to avoid any overflow

        // amount is zero, coins needed is zero
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;

        // variation of knapsack problem
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amt + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][amt] > amt)
            return -1;
        else
            return dp[n][amt];
    }
};

int main()
{
    return 0;
}