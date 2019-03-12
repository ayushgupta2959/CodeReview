/*
Theory
balance_factor = height(left_subtree)-height(right_subtree)
if(abs(balance_factor)>1) there is need to balance the tree
height of leaf nodes is considered as zero
height of null nodes is -1
*/
#include<bits\stdc++.h>
using namespace std;

template <class T>
class Node{
public:
    T data;
    Node *lc;
    Node *rc;
    int h;
    Node(T data,Node<T> *lc,Node<T> *rc){
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
template <class T>
class AVL{
private:
    Node<T> *root;
    int n;
public:
    AVL(){
        root=NULL;
        n=0;
    }
    Node<T>* insert(Node<T> *x,T dta){
        if(x==NULL)                 return new Node<T>(dta,NULL,NULL);
        if(dta < x->data)           x->lc = insert(x->lc,dta);
        else if(dta > x->data)      x->rc = insert(x->rc,dta);
        if(abs(x->lc->height() - x->rc->height())>1) x = balance(x);
        x->h = max(x->lc->height(),x->rc->height()) + 1;
        return x;
    }
    void insert(T dta){
        root = insert(root,dta);
        n++;
    }
    Node<T>* remove(Node<T> *x,T dta){
        if(x==NULL)            return NULL;
        if(dta < x->data)      x->lc = remove(x->lc,dta);
        else if(dta < x->data) x->rc = remove(x->rc,dta);
        else{
            if(x->lc==NULL&&x->rc==NULL) { delete(x);return NULL;}
            else if(x->lc==NULL)         {Node<T> *xr = x->rc; delete(x);return xr;}
            else if(x->rc==NULL)         {Node<T> *xl = x->lc; delete(x);return xl;}
            else{
                x->data = inorder_successor(x)->data;
                x->rc=remove(x->rc,x->data);
            }
        }
        if(abs(x->lc->height() - x->rc->height())>1) x = balance(x);
        x->h = max(x->lc->height(),x->rc->height()) + 1;
        return x;
    }
    void remove(T dta){
        root = remove(root,dta);
        n--;
    }
    Node<T>* balance(Node<T> *x){
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
    Node<T>* llc(Node<T> *x){
        x = right_rotate(x);
        return x;
    }
    Node<T>* lrc(Node<T> *x){
        x->lc = left_rotate(x->lc);
        x = right_rotate(x);
        return x;
    }
    Node<T>* rrc(Node<T> *x){
        x = left_rotate(x);
        return x;
    }
    Node<T>* rlc(Node<T> *x){
        x->rc = right_rotate(x->rc);
        x = left_rotate(x);
        return x;
    }
    Node<T>* left_rotate(Node<T> *parent){
        Node<T> *child = parent->rc;
        parent->rc = child->lc;
        child->lc = parent;
        parent->h = max(parent->lc->height(),parent->rc->height()) + 1;
        child->h = max(child->lc->height(),child->rc->height()) + 1;
        return child;
    }
    Node<T>* right_rotate(Node<T> *parent){
        Node<T> *child = parent->lc;
        parent->lc = child->rc;
        child->rc = parent;
        parent->h = max(parent->lc->height(),parent->rc->height()) + 1;
        child->h = max(child->lc->height(),child->rc->height()) + 1;
        return child;
    }
    Node<T>* inorder_successor(Node<T> *x){
        if(x->rc==NULL) return NULL;
        x = x->rc;
        while(x->lc!=NULL) x = x->lc;
        return x;
    }
    void inorder(Node<T> *x){
        if(x==NULL) return;
        inorder(x->lc);
        cout<<"("<<x->data<<","<<x->height()<<") ";
        inorder(x->rc);
    }
    void display_inorder(){
        inorder(root);
        cout<<"\n";
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    AVL<int> a;
    a.insert(1);
    a.display_inorder();
    a.insert(2);
    a.display_inorder();
    a.insert(3);
    a.display_inorder();
    a.insert(4);
    a.display_inorder();
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.display_inorder();
    a.remove(4);
    a.display_inorder();
    a.remove(5);
    a.display_inorder();
    a.remove(6);
    //after remove 6 two trees are possible
    //it is implementation dependent that how one handle the case when x->lc->height()-x->rc->height()==0
    a.display_inorder();
    a.remove(3);
    a.display_inorder();
    a.remove(2);
    a.display_inorder();
    a.remove(7);
    a.display_inorder();
    a.remove(1);
    a.display_inorder();
    a.remove(7);
    a.display_inorder();
    return 0;
}
