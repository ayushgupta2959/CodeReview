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
class Stack{
private:
    int n;
    Node *top;
public:
    Stack(){
        n=-1;
        top = NULL;
    }
    void push(int dta){
        n++;
        if(top==NULL){ top = new Node(dta,NULL);return;}
        Node *a = new Node(dta,NULL);
        a->next = top;
        top = a;
        return;
    }
    void pop(){
        if(n==-1) {cout<<"Underflow!! Stack is empty\n";return;}
        Node *temp = top;
        top=top->next;
        delete(top);
        n--;
    }
    void display(){
        Node *x = top;
        cout<<"top -> ";
        while(x) {cout<<x->data<<" -> "; x = x->next;}
        cout<<"null\n";
    }

};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Stack s;
    s.push(1);
    s.push(2);
    s.push(-1);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.pop();
    s.pop();
    s.display();
    return 0;
}
