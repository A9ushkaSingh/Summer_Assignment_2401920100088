class Solution {
public:
int lengthOfLongestSubstring(string s) {
        unordered_set<char> ust;

        int left = 0;
        int sol = 0;

        for (int right = 0; right < s.size(); right++)
         {
        while (ust.count(s[right])) 
        {
                ust.erase(s[left]);
                left++;
            }

            ust.insert(s[right]);
            sol = max(sol, right - left + 1);
            
        }

        return sol;
    }
};
