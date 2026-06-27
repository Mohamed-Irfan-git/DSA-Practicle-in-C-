#include <stdio.h>

#define MAX_SIZE 10

typedef struct Stack {
    int arr[MAX_SIZE];
    int top;
    int size;
}Stack;


int isEmpty(Stack * st){
    return st->top == -1;

}

int isFull(Stack *st){
    return st->top == MAX_SIZE  -1;
}

void init(Stack * st){
    st->top = -1;
    st->size = 0;
}

void push(Stack * st,int data){
    if(isFull(st)){
        printf("Stack is overflow\n");
        return;
    }
    
    st->top = st->top +1;
    st->arr[st->top] = data;
    st->size++;

}


int pop(Stack * st){
    if(isEmpty(st)){
        printf("underflow..\n");
        return -1;
    }

    int val = st->arr[st->top];
    st->top--;
    st->size--;
    return val;
}

int peek(Stack * st){
    if(isEmpty(st)){
        printf("stack is empt\n");
        return -1;
    }

    return st->arr[st->top];
}

void print(Stack * st){
    for (int i = 0; i < st->size; i++){
        printf("%d ",st->arr[i]);
    }
    printf("\n");
    

}



int main(){
    Stack st;
    init(&st);
    push(&st,12);

    push(&st,15);
    push(&st,105);
    push(&st,13);
    push(&st,18);

    pop(&st);

    printf("%d\n",peek(&st));

    print(&st);
    return 0;
}





