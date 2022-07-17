#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[105][10005]; // memoization table
    int superEggDrop(int k, int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }

    int solve(int e, int f)
    {
        // if number of floor is 0 then no attempt can be made
        // if number of floor is 1 then only one attempt can be made, irrespective of number of egss

        if (f == 0 || f == 1)
            return f;

        // if number of eggs == 1
        // then the optimal way is to check floor by floor
        // so in worst case it may take f attemps (number of flools -> doesn't break till top)

        if (e == 1)
            return f;

        // check if already there's a value already calculated for current config
        if (dp[e][f] != -1)
            return dp[e][f];

        // now we will check floor by floor
        int ans = INT_MAX;
        for (int k = 1; k <= f; k++)
        {
            // at kth floor there are may be two conclusions

            // when fall breaks egg
            // this means that the threshold is below the kth floor, also we lost 1 egg
            // now we will check for floor height of k-1

            // when egg doesn't break
            // this means that threshold not reached may be above kth floor, no egg lost
            // we will check for rest of floor height with same amount eggs

            // this done optimize it more
            int leftPart, rightPart;
            if (dp[e - 1][k - 1] != -1)
                leftPart = dp[e - 1][k - 1];
            else
            {
                leftPart = solve(e - 1, k - 1);
                dp[e - 1][k - 1] = leftPart;
            }

            if (dp[e][f - k] != -1)
                rightPart = dp[e][f - k];
            else
            {
                rightPart = solve(e, f - k);
                dp[e][f - k] = rightPart;
            }

            int tempAns = 1 + max(leftPart, rightPart);
            ans = min(ans, tempAns);
        }

        return dp[e][f] = ans;
    }
};

int main()
{

    return 0;
}