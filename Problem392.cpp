class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s.length()==0){
            return true;
        }
        int i = 0;
        int j=0;
        while(j<t.length() && i<s.length()){
            if(s.charAt(i)==t.charAt(j)){
                i++;
            }
            j++;
        }
        return i == s.length();
    }
}
