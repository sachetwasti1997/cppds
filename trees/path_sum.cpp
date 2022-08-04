class Solution {
public:
    bool pathSum(TreeNode *r, int sum){
        if(!r){
            return false;
        }
        if((r->val == sum) && !r->left && !r->right)return true;
        return pathSum(r->left, sum - r->val) || pathSum(r->right, sum - r->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        return pathSum(root, targetSum);
    }
};