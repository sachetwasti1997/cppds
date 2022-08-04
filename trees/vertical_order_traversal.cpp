typedef vector<vector<int>> v_vec;
typedef vector<int> vec;

class Solution {
public:

  struct Node{
    TreeNode *n;
    int pos;
  	Node(TreeNode *x, int y): n(x), pos(y){}
  };

  v_vec verticalOrder(TreeNode* root) {
    if(!root)return v_vec();
    queue<Node *> q;
    v_vec res;
    unordered_map<int, vec> u;
    q.push(new Node(root, 0));
    in sz = q.size();
    vec t1{};
    while(!q.empty()){
      vec t;
      for(int i=0; i< sz; i++){
        auto tmp = q.top();
        if(!m.count(tmp->pos))m[tmp->pos] = vec();
        m[tmp->pos].emplace_back(tmp->n->val);
        q.pop();
        if(tmp -> n -> left){
          q.push(new Node(tmp->n->left, tmp->pos - 1));
        }
        if(tmp->n->right){
          q.push(new Node(tmp->n->right, tmp->pos + 1));
        }
        delete tmp;
      }
    }
    int min = INT_MAX;
    for(auto &i: m){
      if(i.first < min)min = i.first;
    }
    while(true){
      if(!m.count(min))break;
      res.emplace_back(m[min++]);
    }
	}
	
};