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

node* Itmerge(node* &head1,node* &head2){
    node*ptr1=head1;
    node*ptr2=head2;
    node*dummyNode = new node(-1);
    node*ptr3 = dummyNode;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    while(ptr1!=NULL){
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    return dummyNode->next;
}

node* Remerge(node* &head1, node* &head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    node*result;
    if(head1->data<head2->data){
        result = head1;
        result->next=Remerge(head1->next, head2);
    }else{
        result = head2;
        result->next=Remerge(head1, head2->next);
    }
    return result;
}



void display(node* head){
    node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node*head1=NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    node*head2=NULL;
    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 6);
    display(head1);
    display(head2);
    node* mergedList = Remerge(head1, head2);
    display(mergedList);
}