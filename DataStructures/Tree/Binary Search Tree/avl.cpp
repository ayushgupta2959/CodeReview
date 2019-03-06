#include<bits\stdc++.h>
using namespace std;
class Data{
public:
    int data;
    Data(int data){
        this->data = data;
    }
};
class Node{
public:
    Data data;
    Node *lc;
    Node *rc;
    Node(Data data,Node *lc,Node *rc){
        this->data = data;
        this->lc = lc;
        this->rc = rc;
    }
};
class AVL{
private:
    Node *root;
    int n;
public:
    AVL(){
        root=NULL;
        n=0;
    }
    Data make_data(int dta){
        Data d(dta);
        return d;
    }
    Node* insert(Node *x,Data dta){
        if(x==NULL) return new Node(dta,NULL,NULL);

    }
    void insert(int dta){
        root = insert(root,make_data(dta));
    }


};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
