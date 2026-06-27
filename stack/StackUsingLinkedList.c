#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node * createNode(int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
 

}

int size = 0;

typedef struct Stack{
    Node * head;
    Node * tail;

}Stack;

void init(Stack * st){
    st->head = NULL;
    st->tail = NULL;

}



int isEmpty(Stack  *st){
    return st->head == NULL;
    
}


void push(Stack * st,int data){
    Node * newNode = createNode(data);

    if(st->head == NULL){
        st->head = st->tail = newNode;
    } else {
        st->tail->next = newNode;
        st->tail = newNode;
    }
}

int pop(Stack * st){
    if(isEmpty(st)){
        printf("stack underflow..\n");
        return -1;
    }

    Node * temp = st->head;
    Node * prev = NULL;

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    int val = temp->data;

    if(prev == NULL){
        st->head = st->tail = NULL;
    } else {
        prev->next = NULL;
        st->tail = prev;
    }

    free(temp);
    return val;
}

int peek(Stack * st){
    if(isEmpty(st)){
        printf("stack is empty\n");
        return -1;
    }

    return st->tail->data;
}

void print(Stack * st){
    
    Node * temp = st->head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next; 
    }

    printf("\n");
}

int main(){
    Stack st;
    init(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);

    printf("%d \n",peek(&st));

    print(&st);

}