#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node nodetype;
nodetype *head,*todelete,*temp;
void insert(int data , int index){
    nodetype *newnode = (nodetype*)malloc(sizeof(nodetype)); 
    if(!newnode){
        printf("memory allocation failed");
    }
    newnode->data = data;
    newnode->next = NULL;
    if(index == 0){
       newnode->next = head;
       head = newnode;
       return;
    }
    temp = head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of bounds!\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;

}
void remove(int index){
    if (!head) {
        printf("Index out of bounds.\n");
        return;
    }

    if(index == 0){
        temp = head->next;
        free(head);
        head = temp;
        return;
    }

    temp = head;
    for(int i = 0; i < index - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Index out of bounds.\n");
        return;
    }

    todelete = temp->next;
    temp->next = todelete->next;
    free(todelete);
}

void print(){
    temp = head;
    if(!temp){
        printf("Linked list is empty.");
        return;
    }
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");

}
int main(){
    insert(5,0);
    insert(44,1);
    insert(55,2);
    insert(45,3);
    print();
    insert(78,2);
    print();
    remove(0);
    remove(3);
    remove(99);
    print();
    return 0;
}