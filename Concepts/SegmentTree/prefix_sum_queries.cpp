/*
Problem
Given an array of non negative integers.
Perform three types of queries
type 1 : given an index i return the prefix sum till that index
type 2: given an integer s return smallest index with prefix sum >= s
type 3: given an index i and new_val x update the arr[i] to new_val
for type 3 queries -1
input format
n : size of array
q : number of queries
5 -> n
1 2 3 4 5 -> array elements
3 -> q
1 1 0-> return prefix sum till index 1
2 5 0-> return smallest index with sum>= 5
3 1 1 -> update the array index value 1 to 1
*/
#include<bits/stdc++.h>
using namespace std;
int left(int i){
    return i<<1;
}
int right(int i){
    return (i<<1)|1;
}
void build(vector<int> &A,vector<int> &st,int i,int tl,int tr){
    if(tl==tr){ st[i]=A[tl]; return;}
    int tm = (tl+tr)/2;
    build(left(i),tl,tm);
    build(right(i),tm+1,tr);
    st[i] = st[left(i)] + st[right(i)];
    return;
}
int query1(vector<int> &A,vector<int> &st,int i,int tl,int tr,int x){
	if(tl>tr) return 0;
	int tm = (tl+tr)/2;
	if(tm<x){
		
	}
}
vector<int> solve(vector<int> &A,vector<vector<int>> &Q){
    int n = A.size();
    int q = Q.size();
    vector<int> st(4*n);
    vector<int> result;
    build(A,st,1,0,n-1);
    for(auto x:Q){
        if(x[0]==1){
            result.emplace_back(query1(A,st,1,0,n-1,x[1]));
        }
        else if(x[0]==2){

        }
        else{

        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,q;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;++i){
        cin>>A[i];
    }
    cin>>q;
    vector<vector<int>> Q(q,vector<int>(3));
    int a,b,c;
    for(int i=0;i<q;++i){
        cin>>a>>b>>c;
        Q[i] = {a,b,c};
    }
    vector<int> result = solve(A,Q);
    for(auto x:result){
        cout<<x<<" ";
    }
    return 0;
}
