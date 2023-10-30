class Solution {
public:
    static bool comp(int a, int b)
    {
        //x1 -- set bits in a 
        //x2 -- set bits in b
        int x1 = __builtin_popcount(a);
        int x2 = __builtin_popcount(b);
        if(x1!=x2)
            return x1<x2; // return true if x1 is less than x2
        else
            return a<b;  // return true if a is less than b
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp); //sort the given array with respect to comparator
        return arr;
    }
};
