// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
using namespace std;

// two pointer appraoch
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int s_len = s.length();
        int t_len = t.length();

        if (s_len == 0 && t_len == 0)
            return true;

        if (s_len == 0)
            return true;
        if (t_len == 0)
            return false;

        int i = 0, j = 0;
        while (i < s_len && j < t_len && i <= j)
        {
            if (s[i] == t[j])
            {
                i++, j++;
            }
            else
            {
                j++;
            }
        }

        if (i == s_len)
            return true;

        return false;
    }
};

// using DP
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        int dp[m + 1][n + 1];

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // if length of lcs if equal to length of s then it means its totally contained in t
        // range of lcs [0,min(m,n)]
        // this imples that one string will always lies in the other
        int lcs = dp[m][n];
        if (m == lcs)
            return true;

        return false;
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