typedef vector<int> vec_int;

class Solution {
private:
    vec_int v;
public:
    int dfs(int i, int j, int m, int n){
        if(i < 0 || j < 0 || i > m || j > n)return 0;
        if(i == m - 1 && j == n - 1)return 1;
        if(v[i][j] != -1)return v[i][j];
        return v[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
    }
    int uniquePaths(int m, int n) {
        v = vec_int(m, vec_int(n, -1));
        return dfs(0, 0, m, n);
    }
};