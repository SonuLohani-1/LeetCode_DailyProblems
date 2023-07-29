#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length() || s.length() == 1) return false;

        //  Here we  have to keep in mind that we can also swap two equal  chars
        // if all the characters and distinct and the both string are already same we can't do any swap so return false;
        if(s.length() > 26 && s == goal) return true;

        int mismatch_found = 0;
        vector<vector<char>> map_mismatch;
        vector<int> freq(26, 0);
        bool flag = false;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != goal[i])
            {
                if(mismatch_found == 2) return false;
                
                mismatch_found++;
                map_mismatch.push_back({s[i], goal[i]});
            }

            else if (flag == false)
            {
                if(freq[s[i] - 'a'] == 1)
                    flag = true;
                freq[s[i] - 'a']++;
            }
        }

        if(flag == true && mismatch_found == 0) return true;

        if(mismatch_found < 2) return false;

        if(map_mismatch[0][1] == map_mismatch[1][0] && map_mismatch[0][0] == map_mismatch[1][1])
            return true;

        return false;
    }
};
int main()
{
    Solution solution;
    string s = "aa";
    string goal = "aa";
    bool ans = solution.buddyStrings(s, goal);
    cout << ans << endl;
    return 0;
}