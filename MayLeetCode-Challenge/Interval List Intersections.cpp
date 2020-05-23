class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        // sort(a.begin(),a.end());
        // sort(b.begin(),a.end());
        vector<vector<int>>c;
        vector<int>k;
        int n1 = a.size();
        int n2 = b.size();
        for(int i = 0 ; i < n1 ; i++){
            for(int j = 0 ; j < n2 ; j++){
                if((a[i][1] < b[j][0]) || a[i][0] > b[j][1]){
                    continue;
                }
                else{
                    k.push_back(max(a[i][0],b[j][0]));
                    k.push_back(min(a[i][1],b[j][1]));
                    c.push_back(k);
                    k.clear();
                }
            }
        }
        return c;
    }
};
