#include <stdio.h>
#include <stdlib.h>
 
// Define the structure for a linked list node
typedef struct Node {
   int data;
   struct Node* next;
} Node;
 
// Function to create a new node
Node* createNode(int data) {
   Node* newNode = (Node*) malloc(sizeof(Node));
   if (!newNode) {
       printf("Memory error\n");
       return NULL;
   }
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}
 
// Function to insert a new node at the end of the list
void insertNode(Node** head, int data) {
   Node* newNode = createNode(data);
   if (*head == NULL) {
       *head = newNode;
       return;
   }
 
   Node* lastNode = *head;
   while (lastNode->next) {
       lastNode = lastNode->next;
   }
 
   lastNode->next = newNode;
}
 
// Function to display the linked list
void displayList(Node* head) {
   Node* temp = head;
   while (temp) {
       printf("%d -> ", temp->data);
       temp = temp->next;
   }
   printf("NULL\n");
}
 
// Function to free the linked list
void freeList(Node* head) {
   Node* temp;
   while (head) {
       temp = head;
       head = head->next;
       free(temp);
   }
}
 
int main() {
   Node* head = NULL;
   int choice, data;
 
   while (1) {
       printf("\n Linked List Operations:\n");
       printf("1. Insert Node\n");
       printf("2. Display List\n");
       printf("3. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);
 
       switch (choice) {
           case 1:
               printf("Enter the data to insert: ");
               scanf("%d", &data);
               insertNode(&head, data);
               break;
           case 2:
               printf("Linked List: ");
               displayList(head);
               break;
           case 3:
               freeList(head);
               printf("Exiting...\n");
               return 0;
           default:
               printf("Invalid choice. Please try again.\n");
       }
   }
 
   return 0;
}
