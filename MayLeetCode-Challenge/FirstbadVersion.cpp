
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int solve(int n){
        int start = 1;
        int end = n;
        int ans = -1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isBadVersion(mid)==true){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
    int firstBadVersion(int n) {
        return solve(n);
    }
};
