#include<bits/stdc++.h>
using namespace std;

// This is the solution of the daily problem on leetcode 20/07/2023 Asteroid Collision
// https://leetcode.com/problems/asteroid-collision/

// The strategy is to use a stack to store the asteroids. If the current asteroid is positive then we can push it into the stack.
// If the current asteroid is negative then we can pop the asteroids from the stack until the top of the stack is positive and the current asteroid is negative.
// If the current asteroid is negative and the top of the stack is also negative then we can push the current asteroid into the stack.
// The time complexity of this solution is O(n) and the space complexity is O(n).

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i = 0; i<asteroids.size(); i++)
        {
            if(asteroids[i] > 0)
                st.push(asteroids[i]);
            else
            {
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
                    st.pop();
                if(st.empty() || st.top() < 0)
                    st.push(asteroids[i]);
                else if(st.top() == abs(asteroids[i]))
                    st.pop();
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    return 0;
}