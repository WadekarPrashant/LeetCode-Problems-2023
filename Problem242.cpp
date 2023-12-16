class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq_table[256] = {0};
        int i ;
        for(i=0; i<s.length(); i++){
            freq_table[s[i]]++;
        }
         for(i=0; i<t.length(); i++){
            freq_table[t[i]]--;
        }
        for(i=0; i<256; i++){
             if(freq_table[i] != 0)
                 return false;
        }
        
        return true;
    }
};
