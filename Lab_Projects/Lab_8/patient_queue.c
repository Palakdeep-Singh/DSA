#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
     
    int age;
    char name[50];
    int waiting_number;
    struct node *next;

}patient;

patient *front = NULL, *rear = NULL; 

int counter = 0; //helpful for couting patients in queue for assigning patient waiting_number.

//Adding patient in queue.
void enque(char name[],int age){
   
    patient *new = (patient *)malloc(sizeof(patient));
    new->next = NULL;

    //check if there is no one in queue then add the patient with 1 number.
    if(front == NULL && rear == NULL){
        front = rear = new;
        new->age = age;
        new->waiting_number = ++counter; // ++counter to count no. of the patient as he is the first so counter will be 1.
        strcpy(new->name,name); //fetch name and age details.
    }
    else{
              //else add patient and increase the counter to give the waiting number to the patient
        rear->next = new;
        new->age = age;
        new->waiting_number = ++counter;
        strcpy(new->name,name);
        rear = new;
    }
}

//deque the patient after he is checked by the doctor;
//decrease waiting numbers of all the patients after him,
void deque(){
     
     if(front == NULL && rear == NULL) return;

     patient *del = (patient *)malloc(sizeof(patient));
     
     //if there is only single patient left than empty queue by assigning NULL to both front and rear
     if(front == rear){
        del = front;
        front = rear = NULL;
        free(del);
     }
     else{

     del = front;
     front = front->next;
     free(del);

     patient *t = front; //now traverse the patients behind him
     while(t!= rear){
    
        t->waiting_number--;    //decrease patient numbers.
        t = t->next;
     }
     rear->waiting_number--; //as thhe last one was not traversed so decrease the patient number.
     counter--;   //decrease counter by 1 as one patient is checked and dequed.
}
}

//display.
//just traverse from front to rear and print all the details of the patient.
void Display(){

    if(front == NULL && rear == NULL) return;

    patient *t = front;
    
    while(t != rear){

        printf(" %s | %d | %d\n",t->name,t->age,t->waiting_number);
        t = t->next;
    }

    printf(" %s | %d | %d\n",rear->name,rear->age,rear->waiting_number);

}

int main(){

    enque("rahul",19);
    enque("sachin",16);
    enque("harsh",18);
    enque("ram",23);
    enque("shyam",20);
    
    printf(" Name  | Age | Number\n");
    Display();
    printf("\n");
    deque();
    deque();

    enque("sparsh",19);
    deque();
    deque();

    enque("Utkarsh",19);
    printf("\n");
    printf(" Name  | Age | Number\n");
    Display();
    printf("\n");
    return 0;
}