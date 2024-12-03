#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    };
};

void insertAtHead(node* &head , int val){
    node* n = new node(val);
    node*temp =head;
    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }
    while(temp->next !=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head=n;
}

void insertAtTail(node* &head , int val){
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node*temp =head;
    while(temp->next !=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deleteAthead(node*&head){
    node*temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    node* todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}

void Delete(node*&head,int pos){
    node*temp = head;
    int count= 1;
    if(pos == 1){
        deleteAthead(head);
        return;
    }
    while(count!=pos-1){
        temp = temp->next;
        count++;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void display(node* head){
    node* temp = head;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=head);
    cout<<temp->data<<endl;
}

int main(){
    node* head = NULL;
    int arr[]={1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<n; i++){
        insertAtTail(head, arr[i]);
    }
    Delete(head, 2);
    display(head);

    return 0;
}