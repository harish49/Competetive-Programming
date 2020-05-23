class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto p : s){
            mp[p]++;
        }
        string res = "";
        vector<pair<int,int>>v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](pair<int,int> a ,pair<int,int> b){
            return a.second > b.second;
        });
        for(auto p : v){
            while(p.second--){
                res+=p.first;
            }
        }
        return res;
    }
};
