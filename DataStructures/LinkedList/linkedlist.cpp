#include<bits/stdc++.h>
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
//0 based indexing
class LinkedList{
private:
    Node *head;
    int n;
public:
    LinkedList(){
        head = NULL;
        n=0;
    }
    //insert new Node at index i
    void insert(int i,int dta){
        if(i>n) {cout<<"Intermediate nodes not initialized\n"; return; }
        n++;
        Node *temp = head;
        if(head==NULL){head = new Node(dta,NULL); return;}
        if(i==0) {Node *a = new Node(dta,NULL); a->next = temp; head = a;return;}
        while(--i) temp = temp->next;
        Node *temp1 = temp->next;
        temp->next = new Node(dta,NULL);
        temp->next->next = temp1;
        return;
    }
    void remove(int i){
        if(n==0) {cout<<"List is empty\n";return;}
        if(i>=n) {cout<<"Invalid index\n";return;}
        Node *temp = head;
        if(i==0) {head = head->next;delete(temp);return;}
        while(--i)temp = temp->next;
        Node *temp1 = temp->next;
        temp->next = temp->next->next;
        delete(temp1);
    }
    void display(){
        Node *x = head;
        cout<<"head -> ";
        while(x) {cout<<x->data<<" -> "; x = x->next;}
        cout<<"null\n";
    }

};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LinkedList ll;
    //ll.insert(0,1);
    //ll.insert(1,2);
    //ll.insert(0,-1);
    //ll.display();
    ll.remove(0);
    ll.display();
    return 0;
}
