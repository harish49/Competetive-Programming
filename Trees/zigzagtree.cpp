#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node
{
	struct node*left,*right;
	int data;
};
struct node *getnode(int data)
{
	struct node *newnode= new node;
	newnode->data=data;
	newnode->left= NULL;
	newnode->right= NULL;
	
	return newnode;
}
void insert(struct node *root , int data)
{
		queue<struct node*>que;
		que.push(root);
		while(!que.empty())
		{
			struct node *temp = que.front();
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
void printzigzag(struct node *root , int height , bool iter)
{
	if(root==NULL)
	{
		return;
	}
	if(height==1)
	{
		cout<< root->data;
	}
	else if(height>1)
	{
		if(iter)
		{
			 printzigzag(root->left,height-1,iter);
		     printzigzag(root->right,height-1,iter);
			
		}
		else
		{
			printzigzag(root->right,height-1,iter);
			printzigzag(root->left,height-1,iter);
		
		}
		
	}
}

int  height(struct node *root)
{
	if(root== NULL)
	{
		return 0;
	}
	else
	{
		int lheight = height(root->left);
		int rheight = height(root->right);
		
		if(lheight>rheight)
		{
			return lheight+1;
		}
		else
		{
			return rheight+1;
		}
		
	}
}
void zigzag(struct node*root)
{
	int h=height(root);
	
	register int i;
	
	bool iter=false;
	
	cout<<h;
	for(i=1;i<=h;i++)
	{
		printzigzag(root,i,iter);
		
		iter=!iter;
	}
}

int main()
{
	
	long int n , x;
	cin >> n;
	cin >> x;
	
	struct node *root= getnode(x);
	
	register int i;
	for(i=0;i<n-1;i++)
	{
		cin >> x;
		insert(root,x);
	}
	zigzag(root);
}
