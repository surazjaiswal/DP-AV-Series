// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        // subsequence -----
        // think of LCS
        // but only one string is given
        // try to figure out something about pallindrome
        // what if we reverse the string
        // now lets check for the lcs in both strings
        // which results in lcs which are common in both
        // insertions and deletions of non lcs char will make string pallindrome
        // so diff of string length and lcs is the number of insertions/deletions

        string word1 = s;
        reverse(s.begin(), s.end());
        string word2 = s;

        int n = s.length();
        int dp[n + 1][n + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return n - dp[n][n];
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