#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int i=0,j;
	for(int k=1;k<n;++k){
		cin>>j;
		i = i^j^k;
	}
	i = i^n;
	cout<<i;
	return 0;
}