#include <bits/stdc++.h> 

using namespace std; 

const int ALPHABET_SIZE = 26; 

struct trie 
{ 
	struct trie *child[ALPHABET_SIZE]; 

	bool word_end; 
}; 

struct trie *getNode() 
{ 
	struct trie *new_node = new trie; 

	new_node->word_end = false; 

	for (int i= 0;i<ALPHABET_SIZE;i++)
	{ 
		new_node->child[i] = NULL; 
	}	
	return new_node; 
} 
void insert(struct trie *root, string key) 
{ 
	struct trie *current = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int letter = key[i] - 'a'; 
	
		if (current->child[letter]==false)
		{ 
			current->child[letter] = getNode(); 
		}	
		
		current = current->child[letter]; 
	} 

	current->word_end= true; 
} 


bool search(struct trie *root, string key) 
{ 
	struct trie *current = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int letter = key[i] - 'a'; 
		if (current->child[letter]==false)
		{ 
			return false; 
		}
		current = current->child[letter]; 
	} 

	return (current!= NULL && current->word_end); 
} 

void delete() 
int main() 
{ 
	int i,n,searches;
	cin>>n>>searches;
	string keys[n];
	for(i=0;i<n;i++)
	{
		cin>>keys[i];
	}
	struct trie *root = getNode(); 
	for(i=0;i<n;i++) 
	{
		insert(root, keys[i]); 
	}
	string x;
	while(searches--)
	{
		cin>>x;
		if(search(root,x))
		{
			cout<<"Found"<<'\n';
		}
		else
		{
			cout<<"Not Found"<<'\n';
		}
	}
	return 0; 
} 

