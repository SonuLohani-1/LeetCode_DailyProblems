#include<bits/stdc++.h>
using namespace std;
// This is the solution of Daily problem on Leetcode - 26/07/2023 Minimum speed to arrive on time.
// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

// The idea is to use binary search.
// We will find the minimum speed using binary search.
// If the minimum speed is possible, then we will return it.
// Else we will return -1.
// time complexity: O(nlogn)
// space complexity: O(1)

class Solution
{
    public:
        bool isPossible(vector<int>& dist, double hour, int speed)
        {
            double time = 0;
            for (int i = 0; i < dist.size() - 1; i++)
            {
                time += ceil((double)dist[i] / speed);
            }
            time += (double)dist[dist.size() - 1] / speed;
            return time <= hour;
        }

        int minSpeedOnTime(vector<int>& dist, double hour)
        {
            int low = 1, high = 1e7;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (isPossible(dist, hour, mid))
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            if (low == 1e7 + 1)
                return -1;
            return low;
        }
};
int main()
{
    return 0;
}