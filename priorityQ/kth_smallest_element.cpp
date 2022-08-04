class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int i = 0, l = 0, m = 0;
        for(auto &r: matrix){
            for(auto &c: r){
                pq.push(c);
            }
        }
        while(pq.size() > k){
            pq.pop();
        }      
        return pq.top();
    }
};