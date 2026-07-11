/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, int> pos;

    TreeNode* build(vector<int>& preorder, int ps, int pe,
                    vector<int>& inorder, int is, int ie) {

        if (ps > pe || is > ie)
            return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);

        int index = pos[preorder[ps]];
        int leftSize = index - is;

        root->left = build(preorder, ps + 1, ps + leftSize,
                           inorder, is, index - 1);

        root->right = build(preorder, ps + leftSize + 1, pe,
                            inorder, index + 1, ie);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        return build(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1);
    }
};
