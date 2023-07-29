#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int helper(string &s, char c, int k)
    {
        // This function counts the maximum length of substring with at most k, C's;
        int count = 0;
        int start = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (count <= k)
                if (s[i] == c)
                    count++;

            while (count > k)
            {
                if (s[start] == c)
                    count--;
                start++;
                ans = max(ans, (i - start + 1));
            }
        }
        ans = max(ans, (int)(s.size() - start));
        return ans;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        // // Firt method counting the consecutive F with maximum k T's
        // // also counting the consecutive T with maximum k F's
        // int count_T = 0;
        // int count_F = 0;
        // int start = 0;
        // int ans = INT_MIN;
        // for (int i = 0; i < answerKey.size(); i++)
        // {
        //     if (count_T <= k)
        //     {
        //         if (answerKey[i] == 'T')
        //             count_T++;
        //     }
        //     while (count_T > k)
        //     {
        //         if (answerKey[start] == 'T')
        //             count_T--;
        //         start++;
        //         ans = max(ans, (i - start + 1));
        //     }
        // }
        // ans = max(ans, (int)(answerKey.size() - start));

        // // Similarly we can do for count_F
        // start = 0;
        // for (int i = 0; i < answerKey.size(); i++)
        // {
        //     if (count_F <= k)
        //     {
        //         if (answerKey[i] == 'F')
        //             count_F++;
        //     }
        //     while (count_F > k)
        //     {
        //         if (answerKey[start] == 'F')
        //             count_F--;
        //         start++;
        //         ans = max(ans, (i - start + 1));
        //     }
        // }
        // return ans;

        //*** Doing the Same thing using helper function *** 
        return max(helper(answerKey, 'T', k), helper(answerKey, 'F', k));
    }
};

// These are the solution using the method in the editorial
class Solution2 {

public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int left = k;
        int right = n;

        while(left < right)
        {
            int mid = (left + right + 1)/2; // make this biased towards right;

            if(isValid(answerKey, mid, k))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

    bool isValid(string answerKey, int size, int k)
    {
        int n = answerKey.length();
        unordered_map<char, int> counter;
        
        for(int i = 0; i < size; i++)
        {
            char c = answerKey[i];
            counter[c]++;
        }

        if(min(counter['T'], counter['F']) <= k)
        {
            return true;
        }

        for(int i = size; i < n; i++)
        {
            char c1 = answerKey[i];
            counter[c1]++;
            char c2 = answerKey[i-size];
            counter[c2]--;

            if(min(counter['T'], counter['F']) <= k)
            return true;
        }

        return false;
    }
};

class Solution3 {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxSize = k;
        unordered_map<char, int> count;
        for(int i = 0; i < k; i++)
        {
            count[answerKey[i]]++;
        }

        int left = 0;
        for(int right = k; right < answerKey.length(); right++)
        {
            
                count[answerKey[right]]++;

                while(min(count['T'], count['F']) > k)
                {
                    count[answerKey[left]]--;
                    left++;
                }
         

                maxSize = max(maxSize, right - left + 1);
        }
        return maxSize;
    }
};

class Solution4 {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxSize = 0;
        unordered_map<char, int> count;
        for(int right = 0; right < answerKey.length(); right++)
        {
            count[answerKey[right]]++;
            int minor = min(count['T'], count['F']);

            if(minor <= k)
                maxSize++;

            else
                count[answerKey[right - maxSize]]--;
        }

        return maxSize;
    }
};
int main()
{
    string answerKey = "TTFTTFTT";
    int k = 1;
    Solution solution;
    int ans = solution.maxConsecutiveAnswers(answerKey, k);
    cout << ans << endl;
    return 0;
}