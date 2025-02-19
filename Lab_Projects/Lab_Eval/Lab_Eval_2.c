#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
} *first = NULL;

// Function to create a linked list from an array
void create(int *A, int n) {
    struct node *last, *t;
    
    first = (struct node*) malloc(sizeof(struct node));
    first->next = NULL;
    first->data = A[0];
    last = first;
    
    for (int i = 1; i < n; i++) {
        t = (struct node *) malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Function to print the linked list
void display(struct node* p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Function to split the linked list into two halves
struct node* middle(struct node* head) {
    if (head == NULL) return NULL;
    
    struct node* low = head;
    struct node* high = head->next;
    
    // Move 'high' by 2 and 'low' by 1
    while (high != NULL) {
        high = high->next;
        if (high != NULL) {
            low = low->next;
            high = high->next;
        }
    }
    
    return low;
}

// Function to merge two sorted linked lists
struct node* merge(struct node* left, struct node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
    
    // Start with the smaller of the two nodes
    if (left->data < right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

// Function to apply merge sort on the linked list
struct node* merge_sort(struct node* head) {
    // Base case: if the list has 0 or 1 elements
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Split the list into two halves
    struct node* mid = middle(head);
    struct node* left = head;
    struct node* right = mid->next;
    mid->next = NULL; // break the link
    
    // Recursively sort both halves
    left = merge_sort(left);
    right = merge_sort(right);
    
    // Merge the sorted halves
    return merge(left, right);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    create(arr, n);
    
    printf("Original List: ");
    display(first);
    
    first = merge_sort(first);
    
    printf("Sorted List: ");
    display(first);
    
    return 0;
}
