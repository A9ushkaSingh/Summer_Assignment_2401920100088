class Solution {
public:
    string decodeString(string s) {

        stack<int> nums;
        stack<string> strs;

        string c = "";
        int num = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if (ch == '[') {
                nums.push(num);
                strs.push(c);

                num = 0;
                c = "";
            }

            else if (ch == ']') {

                int repeat = nums.top();
                nums.pop();

                string prev = strs.top();
                strs.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += c;
                }

                c = prev + temp;
            }

            else {
                c += ch;
            }
        }

        return c;
    }
};
