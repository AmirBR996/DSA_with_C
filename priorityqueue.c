// priority with ascending order
#include<stdio.h>
#define MAXSIZE 100
int arr[MAXSIZE];
int rear = -1,front = 0;
void isfull(){
    if(rear == MAXSIZE - 1){
        printf("Queue is full.\n");
    }
    printf("Queue is not full.\n");
}
void isempty(){
    if(rear < front){
        printf("Queue is empty.\n");
    }
    printf("Queue is not empty.\n");
}
void enqueue(int data){
    if(rear == MAXSIZE - 1){
        printf("Queue is full.\n");
    }
    rear = rear + 1;
    arr[rear] = data;
    printf("%d is enqueued.\n",data);
}
void dequeue(){
    if(rear < front){
        printf("Queue is empty.\n");
    }
    for(int i = front;i<= rear ;i++){
        for(int j = front;j<=rear-i-1 ;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    }
}
    int data = arr[front];
    front = front + 1;
    printf("%d is dequeued.\n",data);
}
void print(){
    for(int i = front ;i<= rear ;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    enqueue(100);
    enqueue(30);
    enqueue(810);
    enqueue(89);
    enqueue(67);
    enqueue(56);
    enqueue(87);
    print();
    dequeue();
    dequeue();
    print();
    dequeue();
    dequeue();
    print();
    dequeue();
    print();
   return 0;
}

