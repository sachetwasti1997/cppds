class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), res = INT_MIN;
        unordered_set<int> v;
        vector<int> dis(n, -1);
        for(int i = 0; i < n; i++){
                dis[i] = 0;
                v.insert(i);
                int j = i;
                while(j != -1 && dis[j] == -1){
                    dis[j] = 1 + dis[i];
                    j = edges[j];
                }
                if(j != -1)res = max(res, dis[i] + 1 - dis[j]);
        }      
        return res;
    }
};