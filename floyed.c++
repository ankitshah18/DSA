#include "bits/stdc++.h"//header file   
using namespace std; //standard c++ namespace



class node{
    public:
        int data;
        node*next;

        //constructor
        node(int d){
            data = d;
            next = NULL;
        }
};

//Linked class (object oriented)
/*
class LinkedList{
    node*head;
    node*all;
public:
    LinkedList(){

    }
    void insert(int d){

    }
}
*/

//Functions (Procedural Programming)

//Passing a pointer by reference
void insertAtHead(node*&head, int d){

    if(head==NULL){
        head = new node(d);
        return;
    }

    node *n = new node(d);
    n->next = head;
    head = n;
}
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" --> ";
        head = head->next; //its simply mean head++ 
    }
}
int length(node *head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

void insertAtTail(node*head, int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void insertInMiddle(node*&head, int data, int p){
    //corner case
    if(head==NULL or p==0){
        insertAtHead(head,data);
    }
    else if(p > length(head)){
        insertAtTail(head,data);
    }
    else{
        //take p-1 jumps
        int jump=1;
        node*temp = head;
        while(jump <= p-1){
            temp = temp->next;
            jump++; 
        }
        //create a new node
        node*n = new node(data);
        n->next = temp->next;
        temp->next;
    }

}

void deleteHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp = head->next;
    delete head;
    head = temp;
}

//Search Operation
//Liner Search
bool search(node*head, int key){
    node*temp = head;
    while(temp!=NULL){
        if(head->data==key){
            return true;
        }
        head = head->next;
    }
    return false;
}

//recursively
bool searchRecursive(node*head, int key){
    if(head==NULL){
        return false;
    }
    //rec case check at head, remaining linked list
    if(head->data==key){
        return true;
    }
    else{
        return searchRecursive(head->next,key);
    }
}

// void take_input(node*head){

// }

node* take_input_2(){
    int d;
    cin>>d;
    node*head = NULL;

    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

void operator<<(ostream &os, node*head){
    print(head);
    return ; //cout
}

void reverse(node*&head){
    node*C = head;
    node*P = NULL;
    node*N;

    while(C!=NULL){
        //save the next node
        N = C->next;
        //make the current node point to prev
        C->next = P;
        //update P and C take them 1 step forware
        P = C;
        C = N;
    }
    head = P;
}

node* recReverse(node*head){
    //smallest linked list
    if(head->next == NULL or head == NULL){
        return head;
    }
    //rec case
    node* shead = recReverse(head->next);
    node* temp = head->next;
    temp->next = head; 
    // while(temp->next!=NULL){
    //     temp = temp->next;
    // }
    head->next = NULL;
    
    return shead;
}


//Mid Point Runner Technique
node* midpoint(node*head){
    if(head==NULL or head->next==NULL){
        return head;
    }

    node*slow = head;
    node*fast = head->next;

    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


//kth node from the end of the linked list
node* kthNode(node*head, int k){
    int len = 0;
    
    node* temp = head;
    //count the number of nodes in linked list
    while(temp){
        temp = temp->next; 
        len++;
    }

    if(len < k){
        return head;
    }
    if(len >= k){
        temp = head;
        for(int i=0; i< len-k; i++){
            temp = temp->next;
        }
    }
    return temp;
    
}

//Merge tow sorted linked list into one
node* merge(node* a, node* b){
    //base case
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    //take a temporary head pointer 
    node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}

//Merge sort 
//Sort an unsorted linked list
node* mergeSort(node*head){
    //base case
    if(head==NULL or head->next==NULL){
        return head;
    }

    //rec case
    //1. break
    node* mid= midpoint(head);
    node* a = head;
    node* b = mid->next;

    mid->next = NULL; 

    //2. rec sort the two parts
    a = mergeSort(a);
    b = mergeSort(b);

    //3. merge them
    node* c = merge(a,b);
    return c;
}

//make cycle function

void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;

    int count = 1;
    while(temp->next!=NULL){
        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
    
}

bool detectCycle(node* head){
    node* slow = head;
    node* fast = head;
    
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            return true;
        }
    }
    return false;
}

int main(){
    node*head = NULL;
    // node*head2 = take_input_2();
    // cout<<head;
    // reverse(head);
    // head = recReverse(head);
    
    // int k = 3;
    // cout<<head;
    cout<<endl;
    // head = mergeSort(head);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    node* mid = midpoint(head);
    
    print(mid);
    // makeCycle(head,3);
    
    // if(detectCycle(head)){
    //     cout<<"loop present";
    // }
    // else{
    //     cout<<"no loop";
    // }

    // cout<<head;
    // node* term = kthNode(head,k);
    // cout<<term->data;
    
   
    
    /*
    insertAtHead(head,5);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);

    print(head);
    cout<<endl;
    insertAtTail(head,6);
    print(head);
    cout<<endl;
    
    int key;
    cin>>key;
    if(searchRecursive(head,key)){
        cout<<"Element Found";
    }
    else{
        cout<<"Element not found";
    }
    */

    

    return 0;
}