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
    TreeNode* constructTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>& mp){
        if(inStart>inEnd || preStart>preEnd) return NULL;

        TreeNode* node=new TreeNode(preorder[preStart]);
        int inval=mp[node->val];
        int numsleft=inval-inStart;

        node->left=constructTree(preorder,preStart+1,preStart+numsleft,inorder,inStart,inval-1,mp);
        node->right=constructTree(preorder,preStart+numsleft+1,preEnd,inorder,inval+1,inEnd,mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=constructTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};
