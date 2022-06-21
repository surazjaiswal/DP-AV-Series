// https://leetcode.com/problems/coin-change-2/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amt, vector<int> &coins)
    {
        int n = coins.size();
        int dp[n + 1][amt + 1];

        // case 1 : coins array is empty, no way to make any amt
        for (int j = 0; j < amt + 1; j++)
            dp[0][j] = 0;

        // case 2 : amt is zero, this can be made using empty set (no coins)
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 1;

        // variation of unbounded kanpsack
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amt + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amt];
    }
};

int main()
{

    return 0;
}