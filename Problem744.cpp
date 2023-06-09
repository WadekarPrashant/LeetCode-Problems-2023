class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lp =  0 , rp = size(letters) - 1;
        bool flag = false;

        while (lp < rp){
            int mid = (rp + lp) / 2;
            if (good(letters[mid], target)){
                rp = mid;
                flag = true;

            }
            else{
                lp = mid + 1;
            }
        }
       
       return flag ? letters[lp] : ( letters[lp] > target ? letters[lp] : letters[0]);
    }


    bool good(char x, char target){
        if (x > target) return true;
        return false;

    }
};
