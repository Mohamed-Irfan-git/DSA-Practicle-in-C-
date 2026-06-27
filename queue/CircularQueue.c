#include <stdio.h>

#define MAX_SIZE 10

typedef struct Queue{
    int arr[MAX_SIZE];
    int front;
    int rear;
}Queue;

int size = 0;

void init(Queue *q){
    q->front = -1;
    q->rear = -1;

}

int isFull(Queue *q){
    return ((q->rear+1) % MAX_SIZE) ==q->front;
}

int isEmpty(Queue * q){
    return q->rear == -1 && q->front == -1;

}
void enqueue(Queue * q,int data){
    if(isFull(q)){
        printf("queue is full");
        return;
    }

    if(q->front == -1 && q->rear == -1){
        q->front = 0;
        q->rear = 0;

        q->arr[q->rear] = data;

    }
    else{
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->arr[q->rear] = data;
    }
    size++;

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
        q->front = (q->front+1) % MAX_SIZE;
    }
    size--;

}

int peek(Queue * q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return -1;
    }

    return q->arr[q->front];

}

int sizeOf(Queue * q){
    if(isEmpty(q)){
        printf("empty queue");
        return -1;

    }

    if(q->rear >= q->front)
        return q->rear - q->front + 1;

    return MAX_SIZE - q->front + q->rear + 1;
}

int main(){

    return 0;
}