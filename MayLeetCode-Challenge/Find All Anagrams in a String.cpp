class Solution {
public:
    bool check(int a[],int b[]){
        for(int i = 0 ; i < 26 ; i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s2, string s1) {
        if(s1.size()>s2.size()){
            return {};
        }
        int id[26]={0};
        for(int i = 0 ; i < s1.size() ; i++ ){
            id[s1[i]-'a']++;
        }
        int id1[26]={0};
        for(int i = 0 ; i < s1.size() ; i++){
            id1[s2[i]-'a']++;
        }
        int k = s1.size();
        vector<int>v;
        if(check(id,id1)==true){
            v.push_back(0);
        }
        int n = s2.size();
        for(int i = k ; i < n ; i++){
            id1[s2[i-k]-'a']--;
            id1[s2[i]-'a']++;
            if(check(id,id1)==true){
                v.push_back(i-(k-1));
            }
        }
        return v;
    }
};
