#include<bits\stdc++.h>
class demo{
public:
    int x;
    demo(){
        int x=0;
    }
    int get_x(){
        if(this == NULL) return -1;
        else return this->x;
    }
};
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    demo *x = NULL;
    cout<<x->get_x();
    return 0;
}
