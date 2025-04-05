#include <stdio.h>
#include <stdlib.h>

struct sll{

    int data;
    struct sll *next;
}*top = NULL;

void stack(int n){
    
    if(n == 0) return;

    struct sll *t = (struct sll  *)malloc(sizeof(struct sll));
     
    if(top == NULL){
        scanf("%d",&t->data);
        t->next = top;
        top = t;
    }

        for(int i = 1;i<n;i++){
            t = (struct sll  *)malloc(sizeof(struct sll));
            scanf("%d",&t->data);
            t->next = top;
            top = t;
        }
}

void Display(struct sll *t){

    while(t!=NULL){
        printf("%d ",t->data);
        t = t->next;
    }
}

void push(int x){
    struct sll *new = (struct sll *)malloc(sizeof(struct sll));
    
    new->data = x;
    new->next = top;
    top = new;
    
}

void pop_back(){

    if(top == NULL) return;
    
    struct sll *p;
    p = top;

    top = top->next;
    top->next = NULL;
    free(p);

}

int main(){

    int n;
    printf("Enter size of stack: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    stack(n);

    printf("Stack: ");
    Display(top);
    printf("\n");
    
    int x;
    printf("Enter element to push: ");
    scanf("%d",&x);

    push(x);

    printf("Stack after pushing element: ");
    Display(top);

    pop_back();
    printf("\nStack after pop: ");
    Display(top);

    return 0;
}