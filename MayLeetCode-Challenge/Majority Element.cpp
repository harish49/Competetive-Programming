class Solution {
public:
    int majorityElement(vector<int>& a) {
        int maj_ind = 0;
        int count = 1;
        int n = a.size() ; 
        for(int i =1 ; i < n;  i++){
            if(a[i]==a[maj_ind]){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                count = 1;
                maj_ind = i;
            }
        }
        return a[maj_ind];
    }
};
