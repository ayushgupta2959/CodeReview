#include<bits\stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int dta,Node *nxt){
        this->data = dta;
        this->next = nxt;
    }
};
class Queue{
private:
    Node *front;
    Node *back;
    int n;
public:
    Queue(){
        front = back = NULL;
        n=-1;
    }
    void insert(int dta){
        n++;
        if(front==NULL){front = new Node(dta,NULL); back=front;return;}
        Node *a = new Node(dta,NULL);
        back->next = a;
        back = a;
    }
    void remove(){
        if(n==-1){{cout<<"Underflow!! Queue is empty\n";return;}}
        Node *t = front;
        front = front->next;
        delete(t);
        if(n==0){front=back=NULL;}
        n--;
        return;
    }
     void display(){
        Node *x = front;
        cout<<"front -> ";
        while(x) {cout<<x->data<<" -> "; x = x->next;}
        cout<<"back\n";
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Queue q;
    q.insert(0);
    q.insert(1);
    q.insert(0);
    q.display();
    q.remove();
    q.remove();
    q.remove();
    q.display();
    return 0;
    return 0;
}
