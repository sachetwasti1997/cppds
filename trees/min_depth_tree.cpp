class Solution {
public:
    void depth(TreeNode * root, int depth, int &min_depth){
        if(!root)return;
        if(!root -> left && !root -> right)
            if(depth < min_depth)
                min_depth = depth;
        depth(root -> left, depth + 1, min_depth);
        depth(root -> right, depth + 1, min_depth);
    }
    int minDepth(TreeNode* root) {
        int min_depth = INT_MAX;
        depth(root, 1, min_depth);
        return min_depth;
    }
};