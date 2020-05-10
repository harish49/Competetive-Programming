class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int arr[1010] = {0};
        for(int i = 0 ; i < trust.size() ; i++ ){
            arr[trust[i][1]]++;
        }
        int ans = -1;
        for(int i = 1; i <= N ; i++ ){
            if(arr[i]==N-1){
                ans = i;
                break;
            }
        }
        if(ans==-1){
            return -1;
        }
        for(int i = 0 ; i < trust.size() ; i++){
            if(trust[i][0]==ans){
                   return -1;
            }
        }
         return ans;
    }
};
