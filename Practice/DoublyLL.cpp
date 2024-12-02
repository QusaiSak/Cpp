#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void insertAthead(node* &head, int d){
    node* n= new node(d);
    n->next = head;
    if(head!= NULL) head->prev = n;
    head = n;
}

void insertAtTail(node*&head , int d){
    if(head == NULL){
        insertAthead(head, d);
        return;
    }

    node* n = new node(d);
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteAtHead(node* &head){
    node* todel = head;
    head = head->next;
    head->prev = NULL;
    delete todel;
}

void Delete(node* &head , int k ){

    if(k==1){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 0;
    while(temp!=NULL && count!=k){
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!= NULL) temp->next->prev = temp->prev;
    delete temp;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    insertAthead(head, 5);
    display(head);
    Delete(head, 1);
    display(head);
    return 0;
}