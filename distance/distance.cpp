#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long tit=0;
bool visited[1000000];
class node{
	public: long long to;
 	long long distance;
	node(long long a,long long b){
		to=a;
		distance=b;
	}
};
vector<node>vec[1000000];
int dps(long long now,long long sum){
	if(sum>ans){
		ans=sum;
		tit=now;
	}
	for(int i=0;i<vec[now].size();i++){
		if(visited[vec[now][i].to]==0){
			visited[vec[now][i].to]=1;
			dps(vec[now][i].to,sum+vec[now][i].distance);
			visited[vec[now][i].to]=0;
		}
	}
	return 0;
}
int main(){
	long long edges;
	long long a,b,c;
	cin>>edges;
	for(int i=0;i<edges-1;i++){
		cin>>a>>b>>c;
		vec[a].push_back(node(b,c));
		vec[b].push_back(node(a,c));
	}
	visited[1]=1;
    dps(1,0);
    visited[1]=0;
    visited[tit]=1;
    dps(tit,0);
    visited[tit]=0;
    cout<<ans<<endl;
}