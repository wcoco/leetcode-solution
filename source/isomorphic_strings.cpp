class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
            
        char c_map[256];
        bool c_sta[256];
        memset(c_map, 0, sizeof(char) * 256);
        memset(c_sta, 0, sizeof(bool) * 256);
        
        for(int i = 0; i < s.size(); ++i){
            if(c_map[s[i]] == 0){
                if(c_sta[t[i]] == true)
                    return false;
                else{
                    c_map[s[i]] = t[i];
                    c_sta[t[i]] = true;
                }
            }
            else{
                if(c_map[s[i]] != t[i])
                    return false;
            }
        }
        
        return true;
    }
};