class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)return vector<int>(n, 0);
        
        vector<vector<int>> g(n, vector<int>());  
        vector<int> deg(n, 0);

        for(auto &i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
            deg[i[0]]++;
            deg[i[1]]++;
        }
        queue<int> q;
        unordered_set<int> s;
        for(auto &i: deg){
            if(deg[i.first] == 0){
                q.push(i.first);
                s.add(i.first);
            }
        }
        vector<int> res(n);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int tmp = q.front();
                q.pop();
                res.push_back(tmp);
                for(auto &i: g[tmp]){
                    if(!s.count(i)){
                        deg[i]--;
                        if(deg[i] == 0){
                            q.push(i);
                            s.add(i);
                        }
                    }
                }
            } 
        }
        return res;
    }
};