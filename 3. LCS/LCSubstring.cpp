// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // similar to LCS problem
        // but here we need substring which contineuous part
        // so when char do not match then save 0 for that part, like starting fresh

        int dp[n + 1][m + 1];
        int ans = 0; // we need to maintain ans variable as if last char is not same then 0 would be stored in it, which incorrect ->> line 28
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (S1[i - 1] == S2[j - 1])
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        ans = max(ans, dp[i][j]);
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{

    //#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //#endif

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    return 0;
}