class Solution {
public:
    char repeatedCharacter(string s) {
        unorderd_map<char, int> g(s.size());
        char res;
        for(auto &ch: s){
            if(!g.count(ch))g[ch] = 0;
            else{
                res = ch;
                break;
            }
        }
        return res;
    }
};