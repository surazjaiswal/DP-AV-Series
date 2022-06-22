// https://leetcode.com/problems/longest-common-subsequence/

#include <bits/stdc++.h>
using namespace std;

// TLE
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();

        return LCS(text1, m, text2, n);
    }

    // this solution will give TLE
    // time : O(2^N)
    int LCS(string str1, int m, string str2, int n)
    {
        // base case
        // here length of string is 0, not the position
        if (n == 0 || m == 0)
            return 0;

        if (str1[m - 1] == str2[n - 1])
            return 1 + LCS(str1, m - 1, str2, n - 1);
        else
            return max(LCS(str1, m - 1, str2, n), LCS(str1, m, str2, n - 1));
    }
};

// TLE
class Solution
{
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        memset(dp, -1, sizeof(dp));
        return LCS(text1, m, text2, n);
    }

    // this solution will give TLE
    // time : O(2^N)
    int LCS(string str1, int m, string str2, int n)
    {
        // base case
        // here length of string is 0, not the position
        if (n == 0 || m == 0)
            return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        if (str1[m - 1] == str2[n - 1])
            return dp[m][n] = 1 + LCS(str1, m - 1, str2, n - 1);
        else
            return dp[m][n] = max(LCS(str1, m - 1, str2, n), LCS(str1, m, str2, n - 1));
    }
};

// AC
class Solution
{
public:
    int longestCommonSubsequence(string s1, string s2)
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

        return dp[m][n];
    }
};

int main()
{

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    return 0;
}