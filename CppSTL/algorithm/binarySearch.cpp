#include<bits\stdc++.h>
using namespace std;
//applied on monotonic functions
//2 things to do while applying binary_search
//(1) find the search space for example array while working on sorted array to find a value
//(2) find the validation f() :- this function tells whether to move left or right from a given point
//program : to find square root of a number
int min_answer;
int n;
bool myCompare(int const x,int const y){
    int t = (x+y)/2;
    if(t*t<n){
        min_answer = t;
        return true;
    }
    return false;
}
int square_root(){
    min_answer = n+1;
    int nr = n/2;
    vector<int> v(nr);
    for(int i=0;i<nr;i++) v[i] = i;
    binary_search(v.begin(),v.end(),myCompare);
    cout<<min_answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    n = 36;
    square_root();
    return 0;
}
