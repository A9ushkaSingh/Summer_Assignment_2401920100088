class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.size() > s.size())
            return ans;

        vector<int> pFreq(26, 0);
        vector<int> winFreq(26, 0);

        for (int i = 0; i < p.size(); i++) {
            pFreq[p[i] - 'a']++;
            winFreq[s[i] - 'a']++;
        }

        if (pFreq == winFreq)
            ans.push_back(0);

        for (int i = p.size(); i < s.size(); i++) {

            winFreq[s[i] - 'a']++;
            winFreq[s[i - p.size()] - 'a']--;

            if (pFreq == winFreq)
                ans.push_back(i - p.size() + 1);
        }

        return ans;
    }
};
