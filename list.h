#ifndef LIST_H
#define LIST_H

// Definition of a node in the linked list
struct node {
    void* data;           
    struct node* next;    
};

typedef struct node node;         
typedef struct node* list_head;   

// Function to create a new node with the given data
node* create_node(void* data);

// Function to add a new node with the given data to the head of the list
list_head add_node(list_head head, void* data);

// Function to free all nodes in the list
void free_list(list_head head);

// Function to print all nodes in the list using the provided print function
void print_list(list_head head, void (*print)(void*));

// Function to find a node with the given data in the list
// The prec parameter is used to store the address of the previous node
node* find_node(list_head head, void* data, node** prec, int (*compare)(void*, void*));

// Function to remove a node with the given data from the list
// Returns the new head of the list
list_head remove_node(list_head head, void* data, int (*compare)(void*, void*));

// Function to change the data of a node with the given data in the list
// Returns the head of the list
list_head change_node(list_head head, void* data, void* new_data, int (*compare)(void*, void*));

#endif // LIST_H