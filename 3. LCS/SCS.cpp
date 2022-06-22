// https://leetcode.com/problems/shortest-common-supersequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestCommonSupersequence(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();
        int dp[m + 1][n + 1];

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    if (s1[i - 1] == s2[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = m, j = n;
        string lcs = "";
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                lcs.push_back(s1[i - 1]);
                i--, j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end());

        int ans = s1.length() + s2.length() - lcs.length(); // length of SCS

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