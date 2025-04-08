#include<stdio.h>
#define MAX_SIZE 100
int arr[MAX_SIZE];
int top = -1;
int isempty(){
    if(top == -1){
        return 1;
    }
    return 0;
}
int isfull(){
    if(top == MAX_SIZE){
        return 1;
    }
    return 0;
}
void push(int data){
    if(top == MAX_SIZE - 1){
        printf("Stack is full\n");
        return;
    }
    top = top + 1;
    arr[top] = data;
    printf("%d is pushed\n",data); 
}
void pop(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    int data = arr[top];
    top = top - 1;
    printf("%d is popped.\n",data);
}
void display(){
    for(int i = 0;i<=top;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    push(12);
    push(23);
    push(3);
    push(2);
    push(25);
    push(99);
    display();
    pop();
    display();
    return 0;

}

