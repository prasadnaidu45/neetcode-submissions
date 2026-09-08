/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void f(vector<int> &res,Node* root){
        if(root==NULL)
            return;
        for(auto it:root->children){
            f(res,it);
            res.push_back(it->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        f(res,root);
        if(root!=NULL)
        res.push_back(root->val);
        return res;
    }
};