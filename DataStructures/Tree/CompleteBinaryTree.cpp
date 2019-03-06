#include<bits\stdc++.h>
using namespace std;
//__builtin_clz(x) counts leading zeros of the integer
int log2(int x){
    return 32 - __builtin_clz(x) -1;
}
class Node{
public:
    int data;
    Node *lc;
    Node *rc;
    Node(int dta,Node *lc,Node *rc){
        this->data = dta;
        this->lc = lc;
        this->rc = rc;
    }
};
class CompleteBinaryTree{
private:
    Node *root;
    int n;
    bool remove_flag;
public:
    CompleteBinaryTree(){
        root = NULL;
        n=0;
        remove_flag=false;
    }
  //construction
    void insert(int dta){
        n++;
        if(root == NULL){root = new Node(dta,NULL,NULL);return;}
        bitset<32> bn(n);
        Node *t = root;
        for(int i=log2(n)-1;i>0;--i) t = (bn[i]==0)?(t->lc):(t->rc);
        if(bn[0]==0) t->lc = new Node(dta,NULL,NULL);
        else t->rc = new Node(dta,NULL,NULL);
    }
    void remove(Node *x,int dta){
        if(x==NULL) return;
        if(x->data==dta){
            remove_flag = true;
            while((x!=NULL)&&(x->data == dta)){
                if(root==x&&n==1) {root=NULL;return;}
                Node *t = root;
                Node *t1 = NULL;
                bitset<32> bn(n);
                for(int i=log2(n)-1;i>0;--i)t = (bn[i]==0)?(t->lc):(t->rc);
                if(bn[0]==0) t1 = t->lc;
                else t1 = t->rc;
                x->data = t1->data;
                bool return_flag = false;
                if(x==t1) return_flag = true;
                if(bn[0]==0) t->lc = NULL;
                else t->rc = NULL;
                delete(t1);
                n--;
                if(return_flag) return;
            }
        }
        if(x!=NULL)remove(x->lc,dta);
        if(x!=NULL)remove(x->rc,dta);
    }
    void remove(int dta){
        remove_flag=false;
        if(n==0) {cout<<"Underflow !! Tree is empty\n";return;}
        remove(root,dta);
        if(remove_flag) cout<<"data removed\n";
        else cout<<"data does not exist\n";
    }

    //traversal
    void dfs(Node *x){
        if(x==NULL) return;
        dfs(x->lc);
        cout<<x->data<<" ";
        dfs(x->rc);
    }
    void display_dfs(){
        dfs(root);
        cout<<"\n";
    }
    /*void display_bfs(){
        Node *x = root;
        queue<Node> q;
        if()
    }*/

};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    CompleteBinaryTree a;
    a.insert(1);
    //a.display_dfs();
    //a.remove(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.insert(8);
    a.insert(9);
    a.insert(9);
    a.display_dfs();
    a.remove(8);
    a.display_dfs();
    a.remove(1);
    a.display_dfs();
    a.remove(2);
    a.display_dfs();
    a.remove(3);
    a.display_dfs();
    a.remove(4);
    a.remove(5);
    a.remove(6);
    a.remove(7);
    a.remove(9);
    a.remove(5);

    a.display_dfs();
    return 0;
}
