#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node with the given data from the linked list
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    // If the key is found at the beginning
    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }

    // Search for the key to be deleted
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the key is not present in the linked list
    if (current == NULL) {
        printf("Element %d not found in the linked list.\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = current->next;
    free(current);
}

// Function to display the elements of the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to search for an element in the linked list
int search(struct Node* head, int key) {
    struct Node* current = head;
    int position = 0;
    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Key not found
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("4. Search for an element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                int position = search(head, key);
                if (position != -1) {
                    printf("Element %d found at position %d.\n", key, position);
                } else {
                    printf("Element %d not found in the list.\n", key);
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
