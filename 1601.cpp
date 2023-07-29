#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // if someone wants to get to a building then someone should also be going out from that building
    // also there can be situations where two people from different building want to go to a same building in that case we will have to decide which will bring the better results
    // so it is like trying every possible thing and count the number of requests for each case
private:
    int ans = 0;
    void backtracking(int n, unordered_map<int, int> &balance, vector<vector<int>> &requests, int idx, int currCount)
    {
        if (idx == requests.size())
        {
            for (auto it : balance)
            {
                if (it.second != 0)
                    return;
            }
            ans = max(ans, currCount);
            return;
        }
        // for (int i = idx; i < requests.size(); i++)
        // {
        //     balance[requests[i][0]]--;
        //     balance[requests[i][1]]++;
        //     currCount++;
        //     backtracking(n, balance, requests, i + 1, currCount);
        //     balance[requests[i][0]]++;
        //     balance[requests[i][1]]--;
        //     currCount--;
        // }
            balance[requests[idx][0]]--;
            balance[requests[idx][1]]++;
            currCount++;
            backtracking(n, balance, requests, idx+ 1, currCount);
            balance[requests[idx][0]]++;
            balance[requests[idx][1]]--;
            currCount--;
            backtracking(n, balance, requests, idx + 1, currCount);
    }

public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        unordered_map<int, int> balance;
        for (int i = 0; i < n; i++)
            balance[i] = 0;
        backtracking(n, balance, requests, 0, 0);
        return ans;
    }
};
int main()
{
    int n = 5;
    vector<vector<int>> requests = {{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};
    Solution solution;
    int ans = solution.maximumRequests(n, requests);
    cout << ans << endl;
    return 0;
}