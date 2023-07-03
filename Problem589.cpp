class Solution {
public:
    bool buddyStrings(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m)
            return false;
        
        if(s == t) {
            // check if there is a duplicate char
            vector<int> mp(26);
            for(auto c: s)
                if(mp[c - 'a']++)
                    return true;
            return false;
        }

        char have = '#', need = '#';
        int cnt = 0;
        bool ok = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == t[i])
                continue;
            if(++cnt > 2)
                return false;
            if(have == '#') {
                have = s[i];
                need = t[i];
            } else if(s[i] == need && t[i] == have)
                ok = true;
            else
                return false;
        }
        return ok;
    }
};
