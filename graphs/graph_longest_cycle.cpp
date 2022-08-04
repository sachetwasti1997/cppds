typedef unordered_set<int> u_set
typedef vector<int> vec_int;
typedef unordered_map<int, vec_int> map_vec
typedef unordered_map<int, int> map_int

class Solution {
public:
    bool cycle(
        u_set &v, u_set &bv,
        map_vec &g, map_int &d, int node, int dis, int &max_dis 
    ){
        v.insert(node);
        bv.insert(node);
        d[node] = dis;
        for(auto &i: g[node]){
            if(!v.count(i) && cycle(v, bv, g, d, i, dis + 1, max_dis))return true;
            else if(bv.count(i)){
                max_dis = max(max_dis, dis + 1 - d[i]);
                bv.erase(i);
                return true;
            }
        }
        bv.erase(node);
        return false;
    }

    int longestCycle(vector<int>& edges) {
        u_set v(edges.size());
        u_set bv(edges.size());
        map_vec g(edges.size());
        map_int distance(edges.size());
        int max_dis = -1;
        for(int i=0; i<edges.size(); i++)
            edges[i] = vector<int>();
        int k = 0;
        for(auto &i: edges){
            if(i != -1)g[k].push_back(i);
            k++;
        }
        for(int i=0; i< edges.size(); i++)cycle(v, bv, g, distance, i, 0, max_dis);
        return max_dis;
    }
};