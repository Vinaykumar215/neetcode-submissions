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
    int maxSum(TreeNode* node,int& maxsum){
        if(node == NULL) return 0;

        int leftsum=max(0,maxSum(node->left,maxsum));
        int rightsum=max(0,maxSum(node->right,maxsum));
        maxsum=max(maxsum,leftsum+rightsum+node->val);

        return node->val+max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        maxSum(root,maxsum);
        return maxsum;
    }
};
