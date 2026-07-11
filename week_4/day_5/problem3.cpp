/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void encode(TreeNode* root, string &s) {

        if (root == NULL) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        encode(root->left, s);
        encode(root->right, s);
    }

    TreeNode* decode(string &s, int &i) {

        if (i >= s.size())
            return NULL;

        if (s[i] == '#') {
            i += 2;
            return NULL;
        }

        string num = "";

        while (i < s.size() && s[i] != ',') {
            num += s[i];
            i++;
        }

        i++;

        TreeNode* root = new TreeNode(stoi(num));

        root->left = decode(s, i);
        root->right = decode(s, i);

        return root;
    }

    string serialize(TreeNode* root) {
        string s = "";
        encode(root, s);
        return s;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return decode(data, i);
    }
};
