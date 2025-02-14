#include "list.h"
#include <stdlib.h>

static node* create_node(void* data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

list_head add_node(list_head head, void* data){
    node* new_node = create_node(data);
    if(head != NULL){
        new_node->next = head;
    }
    return new_node;
}

void free_list(list_head head){
    node* current = head;
    while(current != NULL){
        node* next = current->next;
        free(current);
        current = next;
    }
}

void print_list(list_head head, void (*print)(void*)){
    node* current = head;
    while(current != NULL){
        print(current->data);
        current = current->next;
    }
}

static node* find_node(list_head head, void* data, node** prec,int (*compare)(void*, void*)){
    node* current = head;
    *prec = NULL;
    while(current != NULL){
        if(compare(current->data, data) == 0){
            return current;
        }
        *prec = current;
        current = current->next;
    }
    return NULL;
}

list_head remove_node(list_head head, void* data, int (*compare)(void*, void*)){
    node* prec;
    node* found = find_node(head, data, &prec, compare);
    if(found == NULL){
        return head;
    }
    if(prec == NULL){
        head = found->next;
    }else{
        prec->next = found->next;
    }
    free(found);
    return head;
}

list_head change_node(list_head head, void* data, void* new_data, int (*compare)(void*, void*)){
    node* prec;
    node* found = find_node(head, data, &prec, compare);
    if(found == NULL){
        return head;
    }
    found->data = new_data;
    return head;
}

