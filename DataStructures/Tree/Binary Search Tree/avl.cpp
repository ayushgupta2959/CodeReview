/*
Theory
balance_factor = height(left_subtree)-height(right_subtree)
if(abs(balance_factor)>1) there is need to balance the tree
height of leaf nodes is considered as zero
height of null nodes is -1
*/
#include<bits\stdc++.h>
using namespace std;
class Data{
public:
    int data;
    Data(int data){
        this->data = data;
    }
    int compare(Data a){
        if(this->data < a.data) return -1;
        else if(this->data > a.data) return 1;
        else return 0;
    }
};
class Node{
public:
    Data data;
    Node *lc;
    Node *rc;
    int h;
    Node(Data data,Node *lc,Node *rc){
        this->data = data;
        this->lc = lc;
        this->rc = rc;
        this->h = 0;
    }
    int height(){
        if(this == NULL) return -1;
        else return this->h;
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
        if(x->data.compare(dta)<0)x->lc = insert(x->lc,dta);
        else if(x->data.compare(dta)>0)x->rc = insert(x->rc,dta);
        if(abs(x->lc->height() - x->rc->height())>1) x = balance(x);
        x->h = max(x->lc->height(),x->rc->height()) + 1;
        return x;
    }
    void insert(int dta){
        root = insert(root,make_data(dta));
        n++;
    }
    Node* balance(Node *x){
        if(x->lc->height() - x->rc->height()>0){
            if((x->lc->lc->height()-x->lc->rc->height())>0) x = llc(x);
            else                                            x = lrc(x);
        }
        else{
            if((x->rc->lc->height()-x->rc->rc->height())>0) x = rlc(x);
            else                                            x = rrc(x);
        }
        return x;
    }

    Node* llc(Node *x){
        x = right_rotate(x);
        return x;
    }
    Node* lrc(Node* x){
        x->lc = left_rotate(x->lc);
        x = right_rotate(x);
        return x;
    }
    Node* rrc(Node *x){
        x = left_rotate(x);
        return x;
    }

    Node* rlc(Node* x){
        x->rc = right_rotate(x->rc);
        x = left_rotate(x);
        return x;
    }
    Node* left_rotate(Node* parent){
        Node* child = parent->rc;
        parent->rc = child->lc;
        child->lc = parent;
        parent->h = max(parent->lc->height(),parent->rc->height()) + 1;
        child->h = max(child->lc->height(),child->rc->height()) + 1;
        return child;
    }
    Node* right_rotate(Node* parent){
        Node* child = parent->lc;
        parent->lc = child->rc;
        child->rc = parent;
        parent->h = max(parent->lc->height(),parent->rc->height()) + 1;
        child->h = max(child->lc->height(),child->rc->height()) + 1;
        return child;
    }
    /*Node* remove(int dta){
        if()
    }*/
    void inorder(Node *x){
        if(x==NULL) return;
        inorder(x->lc);
        cout<<"("<<x->data->data<<","<<x->height()<<") ";
    }
    void display_inorder(){
        inorder(root);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    AVL a;
    a.insert(1);
    a.display_inorder();
    a.insert(2);
    a.display_inorder();
    a.insert(3);
    a.display_inorder();
    a.insert(4);
    a.display_inorder();
    a.insert(5);
    a.display_inorder();
    return 0;
}
