class Solution {
public:
    vector<int> memo;
    
    int backtrack(string& s, int start){
        if(start == s.size()){
            return 1;
        }else if(memo[start] != -1){
            return memo[start];
        }else{
            int ret = 0;
            if(s[start] != '0'){
                ret += backtrack(s, start+1);
                
                if(start+1 < s.size() &&
                   (s[start] == '1' || (s[start] == '2' && s[start+1] <= '6'))){
                    //if there remains >= 2 chars
                    ret += backtrack(s, start+2);
                }
            }
            
            return memo[start] = ret;
        }
    }
    
    int numDecodings(string s) {
        memo = vector<int>(s.size(), -1);
        return backtrack(s, 0);
    }
};
