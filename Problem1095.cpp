class Solution {
public:
int peak_index( MountainArray &mountainArr){
    int low = 0;
    int high = mountainArr.length()-1;
    int mid;
    while(low<high){
        mid = low + (high-low)/2;
        if(mountainArr.get(mid) < mountainArr.get(mid+1)){
            low = mid+1;
        }
        else high = mid;
    }
    return low;
}
int left_half(int low , int high , MountainArray &mountainArr , int target){
    while(low<=high){
        int mid = low + (high-low)/2;
        if(mountainArr.get(mid) == target) return mid;
        else if(mountainArr.get(mid) < target)low = mid+1;
        else high = mid-1;
    }
    return -1;
}
int right_half(int low , int high , MountainArray &mountainArr , int target){
    while(low<=high){
        int mid = low + (high-low)/2;
        if(mountainArr.get(mid) == target) return mid;
        else if(mountainArr.get(mid) > target)low = mid+1;
        else high = mid-1;
    }
    return -1;
}
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIndex = peak_index(mountainArr);
        int left = left_half(0 , peakIndex,mountainArr,target);
        if(left != -1) return left;
        int right = right_half(peakIndex ,mountainArr.length()-1,mountainArr,target);
        if(right != -1) return right;
        return -1;
    }
};
