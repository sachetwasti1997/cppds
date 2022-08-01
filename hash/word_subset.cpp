class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> w2;
        for(auto &w: words2){
            unordered_map<char, int> tmp;
            for(auto &i: w){
                if(!tmp.count(i))tmp[i] = 0;
                tmp[i]++;
            }
            for(auto &k: tmp){
                if(!w2.count(k.first))w2[k.first] = k.second;
                else w2[k.first] = max(w2[i.first], k.second);
            }
        }
        vector<string>res;
        for(auto &w: words1){
            unordered_map<char, int>tmp(w2);
            for(auto &i: w){
                if(tmp.count(i)){
                    if(tmp[i] > 0){
                        tmp[i] --;
                    }
                }
            }
            int flag = 1;
            for(auto &i: tmp){
                if(i.second != 0)flag = 0;
            }
            if(flag == 1)res.add(w);
        }
        return res;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> char_cnt(26, 0), tmp;
        for(auto &i: words2){
            tmp = counter(i);
            for(int j=0; j<26; j++)
                char_cnt[j] = max(tmp[j], char_cnt[j]);
        }
        vector<string> res;
        for(auto &i: words1){
            tmp = counter(i);
          int j;
            for(j = 0; j < 26; j++)
                if(tmp[j] < char_cnt[j])break;
            if(j == 26)res.push_back(i);
        }
      return res;
    }
    
    vector<int> counter(string b){
        vector<int> res(26, 0);
        for(auto &i: b)res[i - 'a']++;
        return res;
    }
};