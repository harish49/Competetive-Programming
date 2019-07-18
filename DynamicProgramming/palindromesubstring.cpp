
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp, vis; 

int go(int i, int j, string &s)
{
        if (i > j)
            return 1;
        if (i == j)
            return 1;
        int &ans = dp[i][j];
        if (vis[i][j])
            return ans;
        vis[i][j] = 1;
        if (s[i] != s[j])
            return ans = 0;

        return ans = go(i + 1, j - 1, s);
}

int countSubstrings(string s)
	{
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        vis.resize(n, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
            {
                ans += go(i, j, s);
            }

        return ans;
}
int main()
{
	string s;
	cin >> s;
	countSubstrings(s);
	for(int i = 0 ; i < dp.size() ; i++ ){
		for(int j = 0 ; j < dp.size(); j++)
			cout<<dp[i][j]<<" ";
		cout<<'\n';
		}
		cout<<'\n';
		for(int i = 0 ; i < vis.size() ; i++ ){
		for(int j = 0 ; j < vis.size(); j++)
			cout<<vis[i][j]<<" ";
		cout<<'\n';
	}
}

