#include <bits/stdc++.h>
using namespace std;

//Structure of Node
class node {
    public:
    int data;
    node*next;
    node(int val){
        data = val;
        next = NULL;
    };
};

void insertAtHead(node* &head , int val){
    node* n = new node(val);
    n->next =  head;
    head = n;
}
void insertAtTail(node* &head , int val){
    node* n = new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void DeleteAtHead(node* &head){
    node* todel = head;
    head = head->next;
    delete(todel);
}
void Delete (node* &head , int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        DeleteAtHead(head);
    }
    node* temp = head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
    node* toDel = temp->next;
    temp->next = temp->next->next;
    delete(toDel);
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head,int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Reverse 
// Iterative
node* itreverse(node* head){
    node* prev = NULL;
    node* current = head;
    node* nextptr;
    while(current!=NULL){
        nextptr = current->next;
        current->next = prev;

        prev = current;
        current = nextptr;
    }
    return prev;
}

// Recursive
node* rereverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newHead = rereverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// K nodes
node* kreverse(node* &head , int k){
    if(head==NULL || head->next==NULL || k<=1){
        return head;
    }
    node* prev = NULL;
    node* current = head;
    node* next;
    int count = 0;
    while(current!=NULL && count<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if(next!=NULL){
        head->next = kreverse(next, k);
    }
    return prev;
}

// Make cycle
 void makecylce(node* head, int pos){
    node*temp = head;
    node*StartNode;
    int count = 1;
    while(temp->next != NULL){
        if(count==pos){
           StartNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = StartNode;
 }

// Detect and remove cycle
bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head){
    if(head==NULL || head->next==NULL){
        return;
    }
    node* slow=head;
    node* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);
    fast = head;
    while(fast->next!= slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

int length(node* head){
    int count = 0;
    node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
// Kth Node
node* kappend(node* head, int k){
    node* newHead;
    node* newTail;
    node* tail = head;

    int l = length(head);
    int count = 1;
    k=k%l;
    while(tail->next!=NULL){
        if(count == l-k){
            newTail = tail;
        }
        if(count ==l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

//intersection of two linklist
void intersect(node* &head1, node* &head2 , int pos){
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}
int intersection(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;

    node*ptr1;
    node*ptr2;

    if(l1>l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }else{
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main(){
    node* head1 = NULL;
    int arr[]={1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<n; i++){
        insertAtTail(head1, arr[i]);
    }
    kreverse(head1,3);
    display(head1);
    return 0 ;
}