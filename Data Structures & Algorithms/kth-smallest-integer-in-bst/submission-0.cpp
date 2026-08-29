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
    void inorder(TreeNode* node,vector<int>& tmp){
        if(!node) return;

        inorder(node->left,tmp);
        if(tmp[0]==0) return;

        tmp[0]--;
        if(tmp[0] == 0){
            tmp[1]=node->val;
            return;
        }
        inorder(node->right,tmp);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp(2);
        temp[0]=k;
        inorder(root,temp);
        return temp[1];
    }
};
