//Inserting or deleting a node...
#include<iostream>
#include <stdio.h>

using namespace std;

struct node{
    int data;
    struct node* next;
}*first = NULL;

void create(int A[],int n){
    struct node *last,*t;
    first = new node;
    first->next = NULL;
    first->data = A[0];
    last = first;
    
    for(int i=1;i<n;i++){
      t = new node;
      t->next = NULL;
      t->data = A[i];
      last->next = t;
      last = t;
    }
}

//Inserting node in linked list..
void insert(int index,int x,int n){
      
      //create a new node
      struct node *t = new node;
      //check if node position entered by user is less then n and greater than 1 else return none;
      if(index<1 || index > n) return;
      
      //if insertion is at beginning then just put the address of first node in new node's next
      // and point first to new node.
      if(index == 1){
           t->next = first;
           t->data = x;
           first = t;
      }

      //else move a pointer upto the desired position.
      else{
      struct node *p = first;
      for(int i=1; i<index;i++){
        p = p->next;
      }
      t->next = p->next;  //put the address of next node in new node's next
      p->next = t;       //and add that node's address in the previous node's next.
      t->data = x;      //enter the data in the new node added.
    }
}

 //Now deleting a node from beginning or particular location.
 void _delete_(int index,int n){
    struct node *p,*q = NULL;  //for deleting the node move two pointers..
    
    if(index<1 || index > n) return;
    
    //if we have to delete the first node..
    //put the first address in that node and point first node to next node
    //then free that node.
    if(index == 1){
        p = first;
        first = p->next;
        free(p);
    }
    
    //for deleting at particular location move the pointer from first node to that node.
    p = first;
    for(int i=1;i<index;i++){
          q = p;  //one q pointer will move 1 step behind the p..
          p = p->next;
    }
    
    //juat add p->next in q->next --> put address of nexts->next in that node
    // and freep the node we are pointing to.
    q->next = p->next;
    free(p);
}

//for displaying the linked list move pointer from first to the last node
// and print data of that particular node each time.
void display(struct node *p){

    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}

// Improved Linear Searching of element in the linked list..
struct node * search(struct node *p ,int x){
  
  //two pointers.
  struct node *q = NULL;
  
  while(p!=NULL){
  if(x == p->data){ 
   q ->next = p->next;  //if element is found point the previous node to next's->next.
   p ->next = first;    //now point that node to first node.
   first = p;          // and point first node to that node hence the node we found will come at first place
   return first;
  }
  q = p;
  p = p->next;
  }
  // in case element is not present then return null.
  return NULL;
}

  //inserting in sorted list..
  //condition is just check if value entered is greater than prev node data. and insert there. 
  void insert_in_sort(struct node *p,int x){
     struct node *q=NULL;
     struct node* t = new node;
     
     t->data = x;
     t->next = NULL;

     if(first == NULL){
      first = t;
     }
     else{
     while(p && p->data < x){  //two pointers q and p insert between p and q.
         q = p;
         p = p->next;
     } 

    if(p == first){  // if element is the smallest then  insert before first node.
      t->next = p;
      first = t;
    }
    else{
      t->next = q->next;
      q->next = t;
    }
  }
}

void remove_duplicates_sorted(){
  // 3 pointers 2 will move consecutively and t for storing node which is to be deleted...
  struct node *q = first, *p = first->next,*t;
   while(p!= NULL){    //loop till we reach end of list.
                      // if not equal then just point both of them to next node.
    if(q->data != p->data){
    q = p;
    p = p->next;
    }  
                    //else just point previous node to p's next node. and delete the p node.
    else{
      q->next = p->next;
      t = p;
      p = p->next;
      delete t;
    }
   }
}

int main(){
    
    int n;
    cout<<"Enter Length of Linked List:";
    cin>>n;

    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];
    
    cout<<"Linked List: ";
    create(A,n);
    display(first);
    
    // int x,index;
    // cout<<"\nIsertion of node after node: ";
    // cin>>index;
    // cout<<"Enter value of node:";
    // cin>>x;
    // insert(index,x,n);
    // cout<<"\nLinked list after inserting node: ";
    // display(first);

    // cout<<"\nDelete node number:";
    // cin>>index;
    // _delete_(index,n);
    // cout<<"Linked List after deleting node: ";
    // display(first);
    
    // cout<<"\nEnter element you want to search in Linked List:";
    // cin>>x;

    // if(search(first,x)){
    //   cout<<"Element Found!\n";
    // }
    // else cout<<"Element Not Found!\n";
    int num;
    cout<<"\nEnter element:";
    cin>>num;
    insert_in_sort(first,num);
    display(first);

    remove_duplicates_sorted();
    cout<<"\nLinked List after removing duplicates: ";
    display(first);
    return 0;
}