#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
	string str;
	stack<int> sta;
	while(getline(cin,str)){
		int length=str.size();
		int a;
		int b;
		for(int i=0;i<length;i++){
			if(str[i]<='9'&&str[i]>='0'){
				sta.push((int)str[i]-48);
			}
			if(str[i]=='+'){
				a=sta.top();
				sta.pop();
				b=sta.top();
				sta.pop();
				sta.push(a+b);
			}
			if(str[i]=='-'){
				a=sta.top();
				sta.pop();
				b=sta.top();
				sta.pop();
				sta.push(b-a);
			}
			if(str[i]=='*'){
				a=sta.top();
				sta.pop();
				b=sta.top();
				sta.pop();
				sta.push(a*b);
			}
		}
		cout<<sta.top()<<endl;
	}	
}