#include<bits/stdc++.h>
using namespace std;
int solve(vector<long long> &A,int I){
	sort(A.begin(),A.end());
	for(auto x:A) cout<<x<<" ";
	cout<<"\n";
	int s,e,n;
	n = A.size();
	long long k = 1<<(min(20,((8*I)/n)));
	s = 0;
	e = upper_bound(A.begin(),A.end(),A[s]+k-1LL)-A.begin();
	cout<<k<<"\n";
	int changes = n-e;
	while(e<n){
		e = upper_bound(A.begin(),A.end(),A[s]+k-1LL) - A.begin();
		changes = min(changes,s+n-e);
		s = upper_bound(A.begin(),A.end(),A[s])-A.begin();
		//break;
	}
	//cout<<s<<" "<<e<<"\n";
	return changes;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int N,I;
	cin>>N>>I;
	vector<long long> A(N);
	for(int i=0;i<N;++i){
		cin>>A[i];
	}
	cout<<solve(A,I);
	return 0;
}
