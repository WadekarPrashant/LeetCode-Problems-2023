class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int freq1[26], freq2[26];
        memset(freq1, 0, sizeof(freq1));
        for (char c : chars) {
            freq1[c-'a']++;
        }
        int sum = 0;
        for (string& word : words) {
            memset(freq2, 0, sizeof(freq2));
            for (char c : word) {
                freq2[c-'a']++;
            }
            bool good = true;
            for (int i = 0; i < 26; i++) {
                good &= (freq1[i] >= freq2[i]);
            }
            if (good) {
                sum += (int) word.size();
            }
        }
        return sum;
    }
};
