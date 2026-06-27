#include <stdio.h>

#define MAX_SIZE 10

typedef struct Queue{
    int arr[MAX_SIZE];
    int front;
    int rear;
}Queue;

void init(Queue *q){
    q->front = -1;
    q->rear = -1;

}

int isFull(Queue *q){
    return q->front == MAX_SIZE - 1;
}

int isEmpty(Queue * q){
    return q->rear == -1 && q->front == -1;

}
void enqueue(Queue * q,int data){
    if(isFull(q)){
        printf("queue is full");
        return;
    }

    if(q->front == -1 && q->rear == 1){
        q->front++;
        q->rear++;

        q->arr[q->rear] = data;

    }
    else{
        q->rear = q->rear + 1;
        q->arr[q->rear] = data;
    }

}

void dequeue(Queue * q){
    if(isEmpty(q)){
        return;
    }

    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }

    else{
        q->front++;
    }

}

int peek(Queue * q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return -1;
    }

    return q->front;

}

int sizeOf(Queue * q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return -1;

    }
    return (q->front - q->rear) + 1;
}

int main(){

    return 0;
}