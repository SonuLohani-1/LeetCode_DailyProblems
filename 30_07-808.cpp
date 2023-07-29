#include<bits/stdc++.h>
using namespace std;
// This is the solution of the daily problem on 30-07-2023 on leetcode - Soup Serving
// https://leetcode.com/problems/soup-servings/

// The idea is to use dynamic programming to solve the problem
// We notice that each serving is of 25ml and we can only serve in multiples of 25
// So we divide the quantity by 25 and solve the problem for that

// There is a great explanation in the editorial of the problem
// https://leetcode.com/problems/soup-servings/solution/

class Solution {
public:
    double memo[200][200];
    double soupServings(int N) {
        if(N >= 5000)
        {
            return 1.0;
        }
        return solve(N, N);
    }
    
    double solve(int a, int b)
    {
        if(a <= 0 && b <= 0)
        {
            return 0.5;
        }
        if(a <= 0)
        {
            return 1.0;
        }
        if(b <= 0)
        {
            return 0.0;
        }
        if(memo[a][b] > 0)
        {
            return memo[a][b];
        }
        return memo[a][b] = 0.25 * (solve(a - 4, b) + solve(a - 3, b - 1) + solve(a - 2, b - 2) + solve(a - 1, b - 3));
    }
};

// This is the bottom up solution of the problem
class Solution {
public:
    double soupServings(int N) {
        if(N >= 5000)
        {
            return 1.0;
        }
        N = (N + 24) / 25;
        vector<vector<double>> dp(N + 1, vector<double>(N + 1));
        dp[0][0] = 0.5;
        for(int i = 1; i <= N; i++)
        {
            dp[0][i] = 1.0;
            dp[i][0] = 0.0;
        }
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                dp[i][j] = 0.25 * (dp[max(i - 4, 0)][j] + dp[max(i - 3, 0)][max(j - 1, 0)] + dp[max(i - 2, 0)][max(j - 2, 0)] + dp[max(i - 1, 0)][max(j - 3, 0)]);
            }
        }
        return dp[N][N];
    }
};

// Solution given in the editorial
class Solution {
public:
    double soupServings(int n) {
        int m = ceil(n / 25.0);
        unordered_map<int, unordered_map<int, double>> dp;

        function<double(int, int)> calculateDP = [&](int i, int j) -> double {
            return (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][j - 1] +
                    dp[max(0, i - 2)][max(0, j - 2)] + dp[i - 1][max(0, j - 3)]) /
                   4;
        };

        dp[0][0] = 0.5;
        for (int k = 1; k <= m; k++) {
            dp[0][k] = 1;
            dp[k][0] = 0;
            for (int j = 1; j <= k; j++) {
                dp[j][k] = calculateDP(j, k);
                dp[k][j] = calculateDP(k, j);
            }
            if (dp[k][k] > 1 - 1e-5) {
                return 1;
            }
        }
        return dp[m][m];
    }
};

int main()
{
    return 0;
}