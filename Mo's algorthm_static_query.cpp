#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int N,Q;
long long current_answer=0;
long long cnt[1000]={0};
long long answers[100500];
int BLOCK_SIZE;
int a[100500];
pair< pair<int, int>, int> query[100500];
void add(int x)
{
	if(cnt[x]==0)
	{
		current_answer++;
	}
	cnt[x]++;
}
void remove(int x)
{
	cnt[x]--;
	if(cnt[x]==0)
	{
		current_answer--;
	}
}
bool sortbyquery(const pair< pair<int, int>, int> &x, const pair< pair<int, int>, int> &y)
{
	int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}
int main()
{
	cin>>N>>Q;
	BLOCK_SIZE=sqrt(N);
    int i,j;
	for(i=0;i<N;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<Q;i++)
	{
		cin>>query[i].first.first>>query[i].first.second;
		query[i].second=i;
	}
	sort(query,query+Q,sortbyquery);
	int mo_left = 0, mo_right = -1;
	for(i=0;i<Q;i++)
	{
		int left=query[i].first.first;
		int right=query[i].first.second;
		while(mo_right < right) {
            mo_right++;
            add(a[mo_right]);
        }
        while(mo_right > right) {
            remove(a[mo_right]);
            mo_right--;
        }

        while(mo_left < left) {
            remove(a[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(a[mo_left]);
        }
        answers[query[i].second] = current_answer;
    }
   for(i=0;i<Q;i++)
   {
   	cout<<answers[i]<<'\n';
   }
}
