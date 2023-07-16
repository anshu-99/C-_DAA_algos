#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number ";
	cin>>n;
	int count=0;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			count++;
		}
	}
	if(count==2){
		cout<<"Prime ";
	}
	else{
		cout<<"Not Prime ";
	}
	return 0;
}
