#include<stdio.h>
#define size 5
int arr[size];
int front = size - 1;
int rear = size - 1;
void isfull(){
    if(front == (rear + 1) % size){
        printf("Queue is full.\n");
    }
    else{
        printf("Queue is not full.\n");
    }
}
void isempty(){
    if(rear == front){
        printf("Queue is empty.\n");
    }
    else{
        printf("Queue is not empty.\n");
    }
}
void enqueue(int data){
    if(front == (rear + 1) % size){
        printf("Queue is full.\n");
        return;
    }
    arr[rear] = data;
    rear = (rear + 1)%size;
    printf("%d is enqueued.\n",data);
}
void dequeue(){
    if(rear == front){
        printf("Queue is empty.\n");
        return;
    }
    int data = arr[front];
    front = (front+ 1)%size;
    printf("%d is dequeued.\n",data);
}
void display(){
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", arr[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(30);
    enqueue(80);
    enqueue(89);
    enqueue(67);
    display();
    dequeue();
    dequeue();
    display();
    dequeue();
    display();
   return 0;
}
