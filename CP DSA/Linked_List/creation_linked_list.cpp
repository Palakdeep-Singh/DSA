#include<iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

//Structure to create the linked list...
struct Node{
    int data;
    struct Node* next;
} *first = NULL;  //make a first pointer and make its address 0.

//Now create a linked list..
void create(int *A,int n){
     
    struct Node* last,*t;   //create 2 pointers one will remain on the previous
                           // another will go next and in previous we store next node's address.

    first = (struct Node*)malloc(sizeof(struct Node)); //create the first node or Head.
    first->next = NULL;   //[ DATA | /0 ] address Null;
    first->data = A[0];
    last = first;      //put the pointer on first .

     //now run loops to create upto the required length.
    for(int i=1;i<n;i++){

        t = (struct Node*)malloc(sizeof(struct Node)); //here create new node.
        t->data = A[i];   //store data and mark its address to null [ data | /0 ]...
        t->next = NULL;  
        last->next = t;  //now put the current node address in the previous one.
        last = t;       //Put the previous pointer to next pointer.
    }
}

//display linked list...
//run loop from first till last and print its data and point it to next address..
void display(struct Node *p){

    if(p!=NULL){
        cout<<p->data<<" ";
        display(p->next);
    }
}
 //just point to next address and at return time print the values..
void Reverse_display(struct Node* p){

    if(p!=NULL){
        
        Reverse_display(p->next);
        cout<<p->data<<" ";
    }
}

//find length of linked list...
int len(struct Node *p){
    
    int length = 0;
    while(p!=NULL){
        p = p->next;
        length++;
    }

    return length;
}

//just finding the sum of linked list elements...
int sum_of_elements(struct Node* p){
    
    int sum = 0;
    while(p!=NULL){
      sum += p->data;
      p = p->next;
    }

    return sum;
}

//Find max min in single scan of linked list...
void max_min(struct Node* p){
    int max = INT_MIN,min = INT_MAX;

    while(p!=NULL){
        if(p->data > max) max = p->data;
        if(p->data < min) min = p->data;
        p = p->next;
    }
    cout<<"Minimum Element of Linked List: "<<min<<endl;
    cout<<"Maximum Element of Linked List: "<<max<<endl;
}


int main(){
    int n;
    cout<<"Enter size of Linked List:";
    cin>>n;

    int A[n];
    cout<<"Enter elements of Linked List:\n";
    for(int i=0;i<n;i++) cin>>A[i];
    
    create(A,n);
    cout<<"\nLinked List:\n";
    display(first);

    cout<<"\nReverse Display:\n";
    Reverse_display(first);
    
    cout<<"\n\nLength of Linked List: "<<len(first)<<endl;

    cout<<"\nSum of data of linked list: "<<sum_of_elements(first)<<endl;
    
    max_min(first);
    free(first);
    return 0;
}