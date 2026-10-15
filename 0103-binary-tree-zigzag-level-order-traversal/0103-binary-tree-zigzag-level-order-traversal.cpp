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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        bool lefttoright=true;

        if(root==NULL) return result;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelsize=q.size();
            vector<int> tmp(levelsize);
            int first=0;
            int last=levelsize-1;

            while(levelsize--){
            TreeNode* t=q.front();
            q.pop();

            if(lefttoright) tmp[first++] = t->val;
            else tmp[last--] = t->val;

            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        result.push_back(tmp);
        lefttoright=!lefttoright;
          
        }

        return result;

    }
};