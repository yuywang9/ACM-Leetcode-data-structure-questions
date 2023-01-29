#include <iostream>
#include <cstring>
using namespace std;
int find(int a,int *fr)
{
    if(fr[a]==a){
    	return a;
	}
    else{
		fr[a]=find(fr[a],fr);
		return fr[a];
	}
}
void uni(int x,int y,int *fr)
{
    int ganga=find(x,fr);
    int gangb=find(y,fr);
    if(ganga!=gangb){
    	fr[ganga]=gangb;
	}
}
int main() {
    int n, m;
	int number=0;
	char relation;
	cin>>n;
	cin>>m;
	int fr[n+1];
    int enemy[n+1];
	memset(enemy,0,sizeof(enemy));
	for(int i=0;i<=n;i++){
        fr[i]=i;
	}
    for(int i=0;i<m;i++){
        int a,b;
        cin>>relation;
        cin>>a;
        cin>>b;
        if(relation=='E'){
            if(enemy[a]==0) {
                enemy[a]=b;
            }
            else if(enemy[a]!=0){
                uni(enemy[a],b,fr);
            }
            if(enemy[b]==0) {
                enemy[b]=a;
            }
            else if(enemy[b]!=0){
            	uni(enemy[b],a,fr);
			}
        }
        if(relation=='F'){
            uni(a,b,fr);
        }
    }
    for(int i=1;i<=n;i++){
        find(i,fr);
    }
    for(int i=1;i<=n;i++){
    	if(i==fr[i]){
    		number++;
		}
		else{
			continue;
		}
	}
    cout<<number;
    cout<<endl;
}