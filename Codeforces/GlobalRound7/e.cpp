#include <bits/stdc++.h>
using namespace std;

#define sp ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

vector<int> st;

void build(int i, int l, int r, vector<int>& p){
	if(l == r){
		st[i] = p[l];
		return;
	}

	int m = (l+r)/2;
	build(i<<1, l, m, p);
	build((i<<1)|1, m+1, r, p);
	st[i] = max(st[i<<1], st[(i<<1)|1]);
}

int query(int i, int l, int r, int ql, int qr){
	if(r < ql ||qr < l) return -1;
	if(l >= ql && r <= qr) return st[i];

	int m = (l+r)/2;
	return max(query(i<<1, l, m, ql, qr), query((i<<1)|1, m+1, r, ql, qr));
}


void update(int i, int l, int r, int qi, int q_val){
	if(r < qi || l > qi) return;
	if(l == r){
		st[i] = q_val;
		return;
	}
	int m = (l+r)/2;
	if(qi <= m) update(i<<1, l, m, qi, q_val);
	else update((i<<1)|1, m+1, r, qi, q_val);

	st[i] = max(st[i<<1], st[(i<<1)|1]);
}

int main() {
	sp;

	////////////////To Remove//////////////
	// freopen("../../input.txt", "r", stdin);
	// freopen("../../output.txt", "w", stdout);
	///////////////////////////////////////

	int n;
	cin>>n;

	vector<int> p(n+1);
	vector<int> reverse_lookup_p(n+1);
	int q;
	st.assign(4*n, -1);

	for(int i = 1; i <= n ; ++i){
		cin>>p[i];
		reverse_lookup_p[p[i]] = i;
	}

	build(1, 1, n, p);

	int range_max;
	int index;

	cout<<st[1]<<" ";

	for(int i = 1; i < n; ++i){
		cin>>q;
		range_max = query(1, 1, n, 1, q);
		index = reverse_lookup_p[range_max];
		swap(p[index], p[q]);
		reverse_lookup_p[p[index]] = index;
		reverse_lookup_p[p[q]] = q;
		p[q] = -1;
		update(1, 1, n, index, p[index]);
		update(1, 1, n, q, p[q]);
		cout<<st[1]<<" ";

	}
	cin>>q;

  	return 0;
}