#include<bits/stdc++.h>
using namespace std;

// This is the daily problem of 19/07/2023 on leetcode Non Overlapping Intervals
// https://leetcode.com/problems/non-overlapping-intervals/

// This is the intution for this problem
// We can sort the intervals according to their  end points
// Then we can traverse the intervals and check if the current interval overlaps with the previous interval
// If it overlaps then we can remove the interval with the larger end point
// The time complexity of this solution is O(nlogn) and space complexity is O(1)

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });
        int ans = 0;
        int prev = 0;
        for(int i = 1; i<intervals.size(); i++)
        {
            if(intervals[i][0] < intervals[prev][1])
            {
                ans++;
                // since the curr intervel is (with greater end point) removed we don't need to increment the prev 
            }
            else
            {
                prev = i;
            }
        }
        return ans;
    }
};

// A more optimized solution is to sort the intervals according to their start points
// and then traverse the intervals and check if the current interval overlaps with the previous interval
// if it overlaps then we can remove the interval with the larger end point
// The time complexity of this solution is O(nlogn) and space complexity is O(1)
class Solution2 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        int ans = 0;
        int prev = 0;
        for(int i = 1; i<intervals.size(); i++)
        {
            if(intervals[i][0] < intervals[prev][1])
            {
                ans++;
                if(intervals[i][1] < intervals[prev][1])
                {
                    prev = i;
                }
            }
            else
            {
                prev = i;
            }
        }
        return ans;
    }
};
int main()
{
    
    return 0;
}