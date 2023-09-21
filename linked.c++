#include "bits/stdc++.h"//header file   
using namespace std; //standard c++ namespace


class node{
  public:
  int data;
  node* next;

  node(int val){
    data = val;
    next = NULL;
  }
};

void insertAtHead(node* &head,int val){

   node* n = new node(val);

  if(head == NULL){
    head = n;
    return;
  }

 
  n->next = head;
  head = n;
}

void insertAtTail(node* &head, int val){


  if(head==NULL){
    head = new node(val);
    return;
  }

  node* temp = head;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  temp->next = new node(val);
}

bool search(node* head, int key){
  node* temp = head;
  while(temp!=NULL){
    if(temp->data == key){
      return true;
    }
    temp = temp->next;
  }
  return false;
}

void display(node* head){
  node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;
}

void deleteNode(node* &head, int val){
  node* temp = head;
  while(temp->next->data!=val){
    temp = temp->next;
  }
  node* todelete = temp->next;
  temp->next = temp->next->next;

  delete todelete;
}

void deleteHead(node* &head){
  if(head==NULL){
    return;
  }
  if(head->next == NULL){
    deleteHead(head);
    return;
  }
  node* todelete = head;
  head = head->next;
  delete todelete;
}

node* reverse(node* &head){
  node* previous = NULL;
  node* current = head;
  node* next;

  while(current!=NULL){
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  return previous;
}

node* recReverse(node* &head){
  if(head->next==NULL or head==NULL){
    return head;
  }

  node* shead = recReverse(head->next);
  head->next->next = head;
  head->next = NULL;

  return shead;
}

node* take_input_2(){
    
    int n;
    cin>>n;
    int d;
    node*head = NULL;

    while(n > 0){
        cin>>d; 
        insertAtTail(head,d);
        
    }
    return head;
}

void buildList(node*&head){
int data,n;
cin>>n;

while(n>0){
	cin>>data;
	insertAtTail(head,data);
	n--;
}
}


node* midPoint(node*head){
  if(head==NULL or head->next==NULL){
        return head;
    }

  node* slow = head;
  node* fast = head->next;

  while(fast!=NULL and fast->next!= NULL){
    fast = fast->next->next;
    slow = slow->next;
    
  }
  return slow;
}

node* reversek(node* &head, int k){
  node* prev = NULL;
  node* curr = head;
  node*next;

  int count = 0;
  while(curr!=NULL && count < k){
    next = curr->next;
    curr->next = prev;  
    prev = curr;
    curr = next;
    count++;
  }
  if(next!=NULL){
    head->next = reversek(next, k);
  }

  return prev;
  
}
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


void makeCycle(node* &head, int pos){
  node* temp = head;
  node* startNode;

  int count = 1;
  while(temp->next!=NULL){
    if(count == pos){
      startNode=temp;
    }
    temp = temp->next;
    count++;
  }
  temp->next = startNode;
}


bool detectCycle(node* &head){
  node* slow = head;
  node* fast = head;
  while(fast!=NULL and fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(fast == slow){
      return true;
    }
  }
  return false;
}

int main(){

  // node* head = take_input_2();
  // insertAtTail(head, 1);
  // insertAtTail(head, 2);
  // insertAtTail(head, 3);
  // insertAtTail(head, 4);
  // insertAtTail(head, 5);
  // display(head);
  // insertAtHead(head, 0);
  // display(head);
  // cout<<search(head, 2);

  // deleteHead(head);
  // node* newhead = recReverse(head);
  // node* mid = midPoint(head);
  // cout<<mid->data;

  // int k = 2;
  // node* newhead = reversek(head,k);
  // display(newhead);

  // makeCycle(head,3);
  //display(head);
  // if(detectCycle(head)){
  //   cout<<"loop present";
  // }
  // else{
  //   cout<<"no loop";
  // }

  // int t;
  // cin>>t;
  // while (t--) {
    
  //   int n1;
  //   node* head = NULL;
  //   buildList(head,  n1);
  //   int n2;
  //   node* head2 = NULL;
  //   buildList(head2, n2);
    
    
  //   merge(head,head2);
  //   display(head);
  // }

  int t;
  cin>>t;
  while(t--){
    int n;
    node* head = NULL;
    node* head2 = NULL;
    buildList(head);
    buildList(head2);
    merge(head,head2);
    display(head);
  }
  return 0;
}