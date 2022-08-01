class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int k = 0, t = grades.size(); 
        while(k + 1 <= t){
            k++;
            t -= k;
        }    
        return k; 
    }
};