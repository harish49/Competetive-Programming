class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int c = 0;
        while(num>0){
            if(num%2 == 0){
                ans = ans+(1<<c);
            }
            num = num>>1;
            c++;
        }
        return ans;
    }
};
