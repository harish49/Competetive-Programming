#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
typedef pair<int,int>cell;
bool isvalid(vector<cell> v ,cell point,int n)
{
	return (point.first>=0 && point.second<n 
				&& point.first<n && point.second>=0 && find(v.begin(),v.end(),point)==v.end());
}
bool solve(vector<cell>&v ,int n , cell &curr)
{
	v.push_back(curr);
	if(curr.first==n-1 && curr.second==n-1){
		return true;
	}
	for(int i = 0 ; i < 4 ; i++ )
	{
		int x = curr.first+(dx[i]*a[curr.first][curr.second]);
		int y = curr.second+(dy[i]*a[curr.first][curr.second]);
		cell point=make_pair(x,y);
		if(isvalid(v,point,n))
		{
			if(solve(v,n,point)){
				return true;
			}
		}
	}
	v.pop_back();
	return false;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i ++ ){
		for(int j = 0 ; j < n ; j++ ){
			cin >> a[i][j];
		}
	}
	vector<cell>v;
	cell point = make_pair(0,0);
	solve(v,n,point);
		for(auto i : v){
			cout<<"["<<i.first<<","<<i.second<<"]"<<' ';
		}
	
}

/*
10
7 1 3 5 3 6 1 1 7 5
2 3 6 1 1 6 6 6 1 2
6 1 7 2 1 4 7 6 6 2
6 6 7 1 3 3 5 1 3 4
5 5 6 1 5 4 6 1 7 4
3 5 5 2 7 5 3 4 3 6
4 1 4 3 6 4 5 3 2 6
4 4 1 7 4 3 3 1 4 2
4 4 5 1 5 2 3 5 3 5
3 6 3 5 2 2 6 4 2 1
*/
