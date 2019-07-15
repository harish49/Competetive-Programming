#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
struct Trie
{
	struct Trie*child[26];
	bool endword;
};
struct Trie*getnode()
{
	struct Trie*newnode=new Trie;
	for(int i = 0 ; i < 26 ; i++ )
	{
		newnode->child[i]=NULL;
	}
	newnode->endword=false;
	return newnode;
}
void insert(struct Trie*root , string s)
{
	struct Trie*temp=root;
	int index;
	for(int i = 0 ; i < s.size() ; i++ )
	{
		index=s[i]-'a';
		if(!temp->child[index])
		{
			temp->child[index]=getnode();
		}
		temp=temp->child[index];
	}
	temp->endword=true;
}
bool isvalid(int i , int j , int row, int col , bool **visited)
{
	return (i>=0 && i<row && j>=0 && j<col && visited[i][j]==false);
}
void search(char boggle[][1000],struct Trie*root ,int row, int col ,bool visited[][1000],int i, int j, string str )
{
	if(root->endword)
	{
		cout<<str<<" ";
	}
	visited[i][j]=true;
	for(int a = 0 ; a < 26 ; a++ )
	{
		int x=i+dx[a];
		int y=j+dy[a];
		if(isvalid(x,y,row,col,visited))
		{
			char p = boggle[x][y];
			if(root->child[p])
			search(boggle,root->child[p],row,col,visited, x,y ,str+p);
		}
	}
	visited[i][j]=false;
}
void findword(struct Trie*root,int row,int col,char **boggle)
{
	bool visited[row][col];
	memset(visited,false,sizeof(visited));
	string str="";
	
	for(int i = 0 ; i < row ; i++ )
	{
		for(int j = 0 ; j < col ; j++ )
		{
			if(root->child[boggle[i][j]-'a'])
			{
				memset(visited,false,sizeof(visited));
				str="";
				str+=boggle[i][j];
				search(boggle,root->child[boggle[i][j]-'a'],row,col,visited,i,j,str);
			}
		}
	}
}
int main()
{
	int row,col,query;
	cin >> row >> col >> query;
	char boggle[row][col];
	string s;
	struct Trie*root=new Trie;
	while(query--)
	{
		cin >> s;
		insert(root,s);
	}
	for(int i = 0 ; i < row ; i++ )
	{
		for(int j = 0 ; j < col ; j++ )
		{
			cin >> boggle[row][col];
		}
	}
	findword(root,row,col,boggle);
}
