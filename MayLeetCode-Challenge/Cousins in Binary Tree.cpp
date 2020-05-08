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
    void level(TreeNode* root,int data,int lvl,int &k1)
    {
        if(root==nullptr){
            return;
        }
        if(root->val == data){
            k1 = lvl;
            return;
        }
        level(root->left,data,lvl+1,k1);
        level(root->right,data,lvl+1,k1);
        return;
        
    }
    bool check(TreeNode* root ,int x,int y){
        if(root==nullptr){
            return false;
        }
        return (root->left && root->right && ((root->left->val==x && root->right->val==y) || (root->left->val==y &&root->right->val==x)) || check(root->left,x,y) || check(root->right,x,y) );
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int k,k1;
        level(root,x,0,k);
        level(root,y,0,k1);
        if(k!=k1){
            return false;
        }
        return !check(root,x,y);
        
    }
};
