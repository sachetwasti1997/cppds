bool symmetricdfs(TreeNode * p, TreeNode * q){
      if(!p && !q)return true;
      else if(!p || !q)return false;
      if(p -> val != q -> val)return false;
      return symmetricdfs(p -> left, q -> right) && symmetricdfs(p -> right, q -> left);
    }
    bool isSymmetric(TreeNode* root) {
        return symmetricdfs(root->left, root -> right);
    }