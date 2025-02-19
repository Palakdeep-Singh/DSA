#include<iostream>
#include <stdio.h>

using namespace std;

struct node{
    int data;
    struct node* next;
}*first = NULL, *second = NULL;

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

void create2(int B[],int n){
    struct node *last,*t;
    second = new node;
    second->next = NULL;
    second->data = B[0];
    last = second;
    
    for(int i=1;i<n;i++){
      t = new node;
      t->next = NULL;
      t->data = B[i];
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

    void display(struct node* p){

        while(p){
            cout<< p->data<<" ";
            p = p->next;
        }
    }
    
    int len(struct node *p){
    
        int length = 0;
        while(p!=NULL){
            p = p->next;
            length++;
        }
    
        return length;
    }

    void _delete_(int value,int n){
        struct node *p,*q = NULL;  //for deleting the node move two pointers..
        p = first;
        //if we have to delete the first node..
        //put the first address in that node and point first node to next node
        //then free that node.
        if(value == 1 && p->data == 1){
            p = first;
            first = p->next;
            free(p);
        }
        
        //for deleting at particular location move the pointer from first node to that node.
        p = first;
        while(p!=NULL && p->data != value){
              q = p;  //one q pointer will move 1 step behind the p..
              p = p->next;
        }
        
        //juat add p->next in q->next --> put address of nexts->next in that node
        // and freep the node we are pointing to.
        q->next = p->next;
        free(p);
    }

    void delete_duplicates(struct node *p){
       
        struct node *q = first;

        if(first==NULL) return;

        int max = p->data;
        while (p != NULL) {
            if (p->data > max) {
                max = p->data;
            }
            p = p->next;
        }

        int hash[max+1];
        
        for(int i=0;i<max+1;i++) hash[i] = 0;
        
        p = first;
        while (p != NULL) {
            hash[p->data]++;
            p = p->next;
        }
        
        p = first;
        q = NULL;
        while(p!= NULL){

            if(hash[p->data]>1){
                if(q == NULL){
                    hash[p->data]--;
                    first = p->next;
                }
                else{
                    hash[p->data]--;
                    q->next = p->next;
                }
                struct node *temp = p;
                p = p->next;
                free(temp);
            }else{
                q = p;
                p = p->next;
            }

        }
    }

    void Reverse_recursion(struct node *q,struct node *p){

        if(p!=NULL){
            Reverse_recursion(p,p->next);
            p->next = q;
        }else{
            first = q;
        }
    }

    void concat(){

           struct node *p = first;
           while(p->next != NULL){
            p = p->next;
           }

           p->next = second; //point to next linked list after 1st ends.
           second = NULL;  // we can remove second pointer but don't use free(second).
    }

    void merging_lists(){
        
    }
int main(){
    int n;
    cout<<"Enter length of linked list: ";
    cin>>n;

    cout<<"Enter elements in linked list:\n";
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];
    
    cout<<"Enter elements in second linked list:\n";
    int B[n];
    for(int i=0;i<n;i++) cin>>B[i];
    create(A,n);
    create2(B,n);

    // cout<<"\nLinked List after reversing:\n";
    // Reverse_recursion(NULL,first);
    // display(first);
    
    cout<<"\nLinked List after deleting duplicates:\n";
    delete_duplicates(first);
    display(first);

    cout<<"\nConcatinating Linked Lists:\n";
    concat();
    display(first);
    return 0;
}