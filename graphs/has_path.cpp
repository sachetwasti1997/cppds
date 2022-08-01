class Solution {
public:
    int R, C, desti, destj;
    vector<vector<int>> dir;
    set<vector<int>> visit;
    bool dfs(vector<vector<int>> &maze, int i, int j, int pi, int pj){
        if(i < R && j < C && i >= 0 && j >= 0 && maze[i][j] != 1 && !visit.count({i, j})){                
            visit.insert({i, j});
            bool bl = false;
            for(auto &d: dir){
                int r = i + d[0], c = j + d[1];
                while(r >= 0 && r < R && c >= 0 && c < C && maze[r][c] == 0){
                    r += d[0], c += d[1];
                }
                r -= d[0], c -= d[1];
                if(r == desti && c == destj)return true;
                if(dfs(maze, i+d[0], j+d[1], d[0], d[1])) return true;
            }
            return false;
        }
        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        R = maze.size(); C = maze.size();
        desti = destination[0]; destj = destination[1];
        dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        return dfs(maze, start[0], start[1], 0, 0);
    }
};