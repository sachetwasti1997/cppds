typedef vector<string> V;

class Solution {
public:
    V findRestaurant(V& list1, V& list2) {
        unordered_map<string, int> s(list1.size());
        int min = INT_MAX;
        int k = 0;
        for(auto &i: list1){
            s[i] = k;
            k++;
        }
        k = 0;
        unordered_map<int, V> res;
        for(auto &i: list2){
            if(s.count(i)){
                s[i] += k;
                if(min > s[i]){
                    min = s[i];
                    res[min].append(i);
                }else if(min == s[i]){
                    res[min].append(i);
                }
            }
        }
        return res[min];
    }
};