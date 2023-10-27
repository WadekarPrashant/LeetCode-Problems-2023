class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }
        
        int maxLen = 0;
        int lo = 0;
        std::string result = s;
        
        for (int i = 0; i < s.length(); i++) {
            expandPalindrome(s, i, i, maxLen, lo);
            expandPalindrome(s, i, i + 1, maxLen, lo);
        }
        
        return result.substr(lo, maxLen);
    }
    
    void expandPalindrome(const std::string& s, int j, int k, int& maxLen, int& lo) {
        while (j >= 0 && k < s.length() && s[j] == s[k]) {
            j--;
            k++;
        }
        if (maxLen < k - j - 1) {
            maxLen = k - j - 1;
            lo = j + 1;
        }
    }
};
