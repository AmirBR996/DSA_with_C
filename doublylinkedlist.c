#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};
typedef struct node nodetype;

nodetype *head = NULL, *temp, *nextnode;

void insert(int data, int index) {
    nodetype *newnode = (nodetype*)malloc(sizeof(nodetype));
    if (!newnode) {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (index == 0) {
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
        return;
    }

    temp = head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of bounds.\n");
        free(newnode);
        return;
    }

    nextnode = temp->next;
    newnode->next = nextnode;
    newnode->prev = temp;
    temp->next = newnode;
    if (nextnode != NULL)
        nextnode->prev = newnode;
}
void remove(int index){
    if (!head) {
        printf("Index out of bounds.\n");
        return;
    }

    if(index == 0){
        temp = head->next;
        if(temp != NULL)
            temp->prev = NULL;
        free(head);
        head = temp;
        return;
    }

    nodetype *todelete;
    temp = head;
    for(int i = 0; i < index - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Index out of bounds.\n");
        return;
    }

    todelete = temp->next;
    nextnode = todelete->next;
    temp->next = nextnode;
    if(nextnode != NULL)
        nextnode->prev = temp;
    free(todelete);
}

void print() {
    temp = head;
    if (!temp) {
        printf("Linked list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert(5, 0);
    insert(44, 1);
    insert(55, 2);
    insert(45, 3);
    print();       
    insert(78, 2);
    print();     
    remove(0);
    remove(3);
    remove(99);
    print();
    return 0;
}
