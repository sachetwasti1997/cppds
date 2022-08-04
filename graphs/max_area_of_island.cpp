typedef vector<vector<int>> v_v_int;
typedef vector<pair<int, int>> v_pr_int;
struct pr_hash{
  size_t operator()(const pair<int, int> &x)const{
    hash<int> hasher;
    return hasher(x.first) ^ hasher(x.second);
  }
};
typedef unordered_set<pair<int, int>, pr_hash> us_pr;

class Solution {
public:
  
  int find_max(v_v_int &g, us_pr &v, v_pr_int &dir, int i, int j){
    if(i >= 0 && i < g.size() && j >= 0 && j < g[0].size() && g[i][j] = 1 && !v.count(i, j)){
      v.insert({i, j});
      int res = 1;
      for(auto &d: dir){
        res += find_max(g, v, dir, i + d[0], j + d[1]);
      }
      return res;
    }
    return 0;
  }

  int maxAreaOfIsland(v_v_int &grid) {
    us_pr pr(grid.size());
    v_pr_int dir{{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    int res = INT_MIN;
    for(int i = 0; i < grid.size; i++)
      for(int j = 0; j < grid[0].size; j++)
        if(!pr.count({i, j}) && grid[i][j] == 1)
          res = max(res, find_max(grid, pr, dir, i, j));
    
    return res;
  }

};