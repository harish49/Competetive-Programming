class Solution {
public:
    int kad(vector<int> a)
    {
        int s = 0;
        int sp = INT_MIN;
        for(int i = 0 ; i < a.size() ; i++ ){
            s+=a[i];
            if(sp < s){
                sp = s;
            }
            if(s < 0){
                s = 0;
            }
        }
        return sp;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        int k = kad(A);
        int res = 0;
        for(int i = 0 ; i < A.size() ; i++ ){
            res+=A[i];
            A[i] = -1*A[i];
        }
        res = res+kad(A);
        cout << kad(A);
        if(res > k && res!=0){
            return res;
        }
        return k;
    }
};
