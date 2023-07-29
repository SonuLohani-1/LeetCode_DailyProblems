#include<bits/stdc++.h>
using namespace std;
// This is the solution of the daily problem on 25/07/2023 on Leetcode- Peak Index in a Mountain Array
// https://leetcode.com/problems/peak-index-in-a-mountain-array/

// The intuition behind this problem is that we can use binary search to find the peak element in the array

class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int low = 0;
        int high = arr.size() - 1;
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(arr[mid] < arr[mid + 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};

int main()
{
    return 0;
}