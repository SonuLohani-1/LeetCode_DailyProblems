#include <bits/stdc++.h>
using namespace std;

// This is the daily problem of 24-07-2023 on Leetcode - 50. Pow(x, n)
// https://leetcode.com/problems/powx-n/

// The intuition behind this problem is to use the binary exponentiation
// to calculate the power of a number. The idea is to use the binary
// representation of the power to calculate the power of a number.

// This is the iterative and more consise solution of this problem
class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0)
            nn = -1 * nn;
        while (nn)
        {
            if (nn % 2)
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else
            {
                x = x * x;
                nn = nn / 2;
            }
        }
        if (n < 0)
            ans = (double)(1.0) / (double)(ans);
        return ans;
    }
};

// This is the recursive solution of this problem
class Solution2
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0)
            nn = -1 * nn;
        ans = pow(x, nn);
        if (n < 0)
            ans = (double)(1.0) / (double)(ans);
        return ans;
    }
    double pow(double x, long long n)
    {
        if (n == 0)
            return 1.0;
        double ans = pow(x, n / 2);
        if (n % 2 == 0)
            return ans * ans;
        else
            return ans * ans * x;
    }
};

// This is my initial solution of this problem
class Solution3
{
public:
    double myPow(double x, int n)
    {
        // since Either x is not zero or n > 0. that is 0^0 is not possible
        if (x == 0)
            return 0; // since n is not zero when x = 0
        if (n == 0 || x == double(1))
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;

        double ans;
        if (n % 2 == 0)
        {
            ans = myPow(x, n / 2);
            return ans * ans;
        }
        if (n % 2 == 1)
        {
            ans = myPow(x, n / 2);
            return ans * ans * x;
        }
        if (n % 2 == -1)
        {
            ans = myPow(x, n / 2);
            return ans * ans * (1 / x);
        }
        return -1;
    }
};
int main()
{
    return 0;
}