class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=1){
            return true;
        }
        bool ok1 = true;
        bool ok2 = true;
        for(int i = 1 ; i < coordinates.size() ; i++){
            if(coordinates[i][0]!=coordinates[i-1][0]){
                ok1 = false;
            }
        }
        for(int i = 1 ; i < coordinates.size() ; i++){
            if(coordinates[i][1]!=coordinates[i-1][1]){
                ok2 = false;
            }
        }
        if(ok1==true || ok2==true){
            return true;
        }
        double slope = (coordinates[1][1]-coordinates[0][1])/(double)(coordinates[1][0]-coordinates[0][0]);
        for(int i = 1 ; i < coordinates.size() ; i++ ){
            double s = (coordinates[i][1]-coordinates[i-1][1])/(double)(coordinates[i][0]-coordinates[i-1][0]);
            if(s!=slope){
                return false;
            }
        }
        return true;
    }
};
