#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
	int rounds;
	cin>>rounds;
	for(int i=1;i<=rounds;i++){//number of test cases
		int size;
		cin>>size;
		stack<int> A;
		for(int j=1;j<=size;j++){
			int num;
			cin>>num;
			A.push(num);
		}//input initial sequence
		int times;
		cin>>times;
		for(int h=0;h<times;h++){//one permutation
			int arr[size];//target sequence
			stack<int> copy=A;
			stack<int> B;
			stack<int> S;
			bool a=true;
			bool b=true;
			for(int z=0;z<size;z++){
				cin>>arr[z];
			}
			while(copy.top()!=arr[0]){
				S.push(copy.top());
				copy.pop();
			}
			S.push(copy.top());
			copy.pop();
			B.push(S.top());
			S.pop();
			for(int v=1;v<size;v++){
				a=true;
				b=true;
				if(S.size()!=0){
					if(S.top()==arr[v]){
					B.push(S.top());
					S.pop();
					}
					else{
						b=false;
					}
				}
				else{
				  	b=false;
				}
				if(b==true){
				    continue;
				}
				if(copy.size()!=0){
					if(copy.top()==arr[v]){
						B.push(copy.top());
						copy.pop();
					}
					else{
						while(copy.top()!=arr[v]){
							S.push(copy.top());
							copy.pop();
							if(copy.size()==0){
								a=false;
								break;
							}
						}
						if(a!=false){
							B.push(copy.top());
							copy.pop();
						}
					}
				}
				else{
					a=false;
				}
				if(a==false&&b==false){
					break;
			   	}
			}
			if(a==false&&b==false){
				cout<<"Impossible"<<endl;
			}
			else{
				cout<<"Aye"<<endl;
			}	
		}
	}
}
