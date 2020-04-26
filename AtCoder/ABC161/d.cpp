#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define v(t) vector<t>
#define vv(t) vector<vector<t>>
#define vn(t,n,val) vector<t>(n,val)
#define vvn(t,r,c,val) vector<vector<t>>(r, vector<t>(c,val))
#define vvv(t) vector<vector<vector<t>>>
#define vvvn(t,l,b,h,val) vector<vector<vector<t>>>(l,vector<vector<t>>(b,vector<t>(h)))

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int k;
	cin>>k;

	// vector<long long> a = {1,2,3,4,5,6,7,8,9};
	// int i = 0;
	// while(a.size() < k){
	// 	int n = log10(a[i]);
	// 	long long pow10 = powl(10,n);
	// 	int val = a[i]/pow10;
	// 	if(val != 1) a.emplace_back((val-1)*pow10*10ll + a[i]);
	// 	a.emplace_back(val*pow10*10ll + a[i]);


	// }

	vector<string> a = {"1","2","3","4","5","6","7","8","9"};
	int i = 0;
	int l;
	string t;

	while(a.size() < k){
		if(a[i].back() != '0'){
			t = a[i];
			t.push_back(a[i].back()-1);
			a.emplace_back(t);
		}
		

		t = a[i];
		t.push_back(a[i].back());
		a.emplace_back(t);

		if(a[i].back() != '9'){
			t = a[i];
			t.push_back(a[i].back() + 1);
			a.emplace_back(t);
		}


		// a.emplace_back(a[i].back())


		// l = a[i].size();
		// string t;
		// t = a[i];
		// if(a[i][l-1] != '1'){
		// 	t.push_back(a[i][l-1]-1);
		// 	a.emplace_back(t);
		// }
		// t = a[i];
		// t.push_back(a[i][l-1]);
		// a.emplace_back(t);
		// t = a[i];
		// if(a[i][l-1] != '9'){
		// 	t.push_back(a[i][l-1]+1);
		// 	a.emplace_back(t);
		// }
		i++;
	}

	// for(auto&x: a) cout<<x<<" ";
	// 	cout<<"\n";

	cout<<a[k-1];

  	return 0;
}