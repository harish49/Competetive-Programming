class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>v[26];
        for(int i = 0 ; i < s.size() ; i++){
            v[s[i]-'a'].push_back(i);
        }
        int ans = INT_MAX;
        for(auto p : v){
            if(p.size()==1){
                ans = min(ans,p[0]);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};
