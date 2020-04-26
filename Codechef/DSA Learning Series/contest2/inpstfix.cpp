#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
unordered_map<char, int> precedence;
void solve(){
	int n;
	cin>>n;
	string a;
	cin>>a;
	string res = "";
	stack<char> st;

	for(auto& x: a){
		if(x >= 'A' && x <= 'Z') res += x;
		else if(x == '(') st.push(x);
		else if(x == ')'){
			while(st.top() != '('){
				res += st.top();
				st.pop();
			}
			st.pop();
		}
		else if(st.empty() || st.top()=='(' || precedence[st.top()] < precedence[x]) st.push(x);
		else{
			while(!st.empty() && precedence[st.top()] >= precedence[x]){
				res += st.top();
				st.pop();
			}
			st.push(x);
		}
	}
	while(!st.empty()){
		res += st.top();
		st.pop();
	}
	cout<<res;
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../../input.txt", "r", stdin);
	// freopen("../../../output.txt", "w", stdout);
	///////////////////////////////////////

	precedence['+'] = 1;
	precedence['-'] = 1;
	precedence['*'] = 2;
	precedence['/'] = 2;
	precedence['^'] = 3;


	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

  	return 0;
}