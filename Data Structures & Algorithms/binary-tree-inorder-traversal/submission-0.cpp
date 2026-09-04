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
    void inorder(vector<int> &res,TreeNode* temp){
        if(temp==NULL)
            return;
        inorder(res,temp->left);
        res.push_back(temp->val);
        inorder(res,temp->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* temp=root;
        vector<int> res;
        inorder(res,temp);
        return res;
    }
};