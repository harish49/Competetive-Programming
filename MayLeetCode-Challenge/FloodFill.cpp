class Solution {
public:
    int m,n;
    int vis[1000][1000];
    void solve(vector<vector<int>> & v,int sr,int sc,int wanted,int paint)
    {
        if(sr<0 || sr>=n || sc<0 || sc>=m){
            return;
        }
        if(v[sr][sc]==wanted && vis[sr][sc]==0){
            v[sr][sc] = paint;
            vis[sr][sc] = 1;
            solve(v,sr,sc+1,wanted,paint);
            solve(v,sr,sc-1,wanted,paint);
            solve(v,sr+1,sc,wanted,paint);
            solve(v,sr-1,sc,wanted,paint);
            return;
        }
        else{
            return;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size()==0){
            return image;
        }
        int color = image[sr][sc];
        n = image.size();
        m = image[0].size();
        solve(image,sr,sc,color,newColor);
        return image;
    }
};
