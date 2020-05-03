
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>a,b;
        for(int i = 0 ; i < ransomNote.size() ; i++){
            a[ransomNote[i]]++;
        }
        for(int i = 0 ; i < magazine.size() ; i++ ){
            b[magazine[i]]++;
        }
        for(auto p : a){
            if(b[p.first]<p.second){
                return false;
            }
        }
        return true;
    }
};
