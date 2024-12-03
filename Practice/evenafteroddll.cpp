#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAthead(node* &head,int d){
    node*n = new node(d);
    n->next = head;
    head = n;
}

void insertAtTail(node*&head , int d){
    if(head==NULL){
        insertAthead(head, d);
        return;
    }
    node* n = new node(d);
    node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}


void display(node* head){
    node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void evenafterodd(node*&head){
    node*odd= head;
    node* even = head->next;
    node*evenstart = even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    
    if(odd->next==NULL){
        even->next = NULL;
    }
}

int main(){
    node* head = NULL;
    int arr[]={1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<n; i++){
        insertAtTail(head, arr[i]);
    }
    display(head);
    evenafterodd(head);
    display(head);
    return 0;
}