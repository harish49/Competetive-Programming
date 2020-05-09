class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int l = 1;
        long long int r = num;
        while(l<=r){
            long long int mid = l+(r-l)/2;
            long long int val = mid*1LL*mid;
            if(val==num){
                return true;
            }
            else if(val>num){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return false;
    }
};
