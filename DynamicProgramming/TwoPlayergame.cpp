class Solution {
public:
    bool divisorGame(int n) {
        
        int a[n+1];
        a[0] = 0;
        a[1] = 0;
        for(int i = 2 ; i<=n ; i++ ){
            int curr = 1;
            for(int j = 1 ; j<i ; j++ ){
                if(i%j==0){
                    curr = curr & a[i-j];
                }
            }
            a[i] = !curr;
        }
        return a[n];
    }
};
