class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &g, vector<int> &v, int node, unordered_set<int> &visit, int dis){
        visit.insert(node);
        v[node] = dis;
        for(auto &nd: g[node]){
            if(!visit.count(nd))dfs(g, v, nd, visit, dis + 1);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        unordered_map<int, vector<int>> graph(n);
        for(int i = 0; i < n; i++)
            graph[i] = vector<int>();
        int i = 0;
        for(auto &k: edges){
            if(k != -1)graph[i].push_back(k);
            i++;
        }
        vector<int> n1(n, -1);
        vector<int> n2(n, -1);
        unordered_set<int> visit(n);
        dfs(graph, n1, node1, visit, 0);
        visit = unordered_set<int>(n);
        dfs(graph, n2, node2, visit, 0);
        int h = 0, res = INT_MAX, res_node = -1;
        for (auto &i: n1){
            if(n2[h] != -1 && i != -1){
                if(res > max(n2[h], i)){
                    res = max(n2[h], i);
                    res_node = h;
                }else if(res == max(n2[h], i)){
                    if(h < res_node)res_node = h;
                }
            }
            h++;
        }
        return  res_node;
    }
    void dfs(vector<int> &e, int n, vector<int> &d, int dis){
        while(n != -1 && dis < d){
            d[n] = dis++;
            n = e[n];
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int res_node = -1;
        vector<int> d1(edges.size, -1);
        vector<int> d2(edges.size, -1);
        dfs(edges, node1, d1, 0);
        dfs(edges, node2, d2, 0);
        int h = 0, res_dis = INT_MAX, res_node = -1;
        for(auto &i: d1){
            if(i != -1 && d2[h] != -1){
                int c_d = max(i, d2[h]);
                if(res_dis > c_d){
                    res_dis = c_d;
                    res_node = h;
                }else if(res_dis == c_d){
                    res_node = h < res_dis ? h : res_node;
                }
            }
            h++;
        }
        return res_node;
    }
};