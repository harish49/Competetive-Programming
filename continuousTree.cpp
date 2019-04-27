#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node *left,*right;
	long int data;
};
struct node *getnode(int data)
{
	struct node *newnode=new node;
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return(newnode);
}
struct node *insert(struct node *temp , int data)
{
	queue<struct node*>que;
	que.push(temp);
	while(!que.empty())
	{
		struct node *temp=que.front();
		que.pop();
		if(!temp->left)
		{
			temp->left=getnode(data);
			break;
		}
		else
		{
			que.push(temp->left);
		}
		if(!temp->right)
		{
			temp->right=getnode(data);
			break;
		}
		else
		{
			que.push(temp->right);
		}
	}
	
}
bool continuous(struct node*root)
{
	if(root==NULL)
	return false;
	
	if(root->left==NULL && root->right==NULL)
	return true;
	
	if(root->left==NULL)
	return (abs(root->data - root->right->data)==1) && continuous(root->right);
	
	if(root->right==NULL)
	return (abs(root->data - root->left->data)==1) && continuous(root->left);
	
	return (abs(root->data - root->right->data) == 1 ) && (abs(root->data - root->left->data ) == 1 ) && continuous(root->left) && continuous(root->right);
}
int main()
{
	int n,x;
	cin >> n;
	register int i;
	struct node *root=getnode(1);
	for(i=0;i<n-1;i++)
	{
		cin >> x;
		insert(root,x);
 	}
 	if(continuous(root))
 	{
 		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}
