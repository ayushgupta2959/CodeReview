#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long n;
	cin>>n;
	if(n>1000000) return 0;
	while(n!=1){
		cout<<n<<" ";
		if(n&1){
			n = n*3+1;
		}
		else{
			n>>=1;
		}
	}
	cout<<1;
	return 0;
}