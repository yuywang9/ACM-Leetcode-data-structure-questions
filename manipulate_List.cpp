// constructing lists
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main (){
	int n;
	cin>>n;
	vector<int> num(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	int steps;
	cin>>steps;
	int indicator;
	int ptr1,ptr2;
	for(int i=1;i<=steps;i++){
		cin>>indicator;
		if(indicator==1||indicator==3){
			cin>>ptr1;
			cin>>ptr2;
			if(indicator==1){
				num.insert(num.begin()+(ptr1),ptr2);
			}
			else{
				reverse(num.begin()+(ptr1-1),num.begin()+(ptr2));
			}
		}
		else{
			cin>>ptr1;
			if(indicator==2){
				num.erase(num.begin()+(ptr1-1));
			}
			else{
				cout<<num[ptr1-1]<<endl;
			}
		}
	}
	return 0;
}
