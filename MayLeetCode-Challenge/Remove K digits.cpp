class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<int>s;
        string res ="";
        for(int i = 0 ; i < nums.size() ;i++ ){
            int val = nums[i]-'0';
            if(s.size()==0 && val==0){
                continue;
            }
            if(s.size()==0){
                s.push(val);
            }
            else{
                while(k>0 && s.size()>0 && s.top()> val){
                    s.pop();
                    k--;
                }
                s.push(val);
            }
        }
         while(k>0 && s.size()>0){
            s.pop();
            k--;
         }
        while(s.size()>0){
            res+=to_string(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        int i = 0;
        while(i < res.size()){
            if(res[i]=='0'){
                i++;
            }
            else{
                break;
            }
        }
        
        res.erase(0,i);
         if(res==""){
            return "0";
        }
        return res;
    }
};
