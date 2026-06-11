class Solution {
public:
    string reverseWords(string s) {

        int start = 0;

        for (int end = 0; end <= s.size(); end++) {

            if (end == s.size() || s[end] == ' ') {

                int left = start;
                int right = end - 1;

                while (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }

                start = end + 1;
            }
        }

        return s;
    }
};
