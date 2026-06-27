#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;

}Node;

typedef struct LinkedList {
    Node * head;
}LinkedList;

void init(LinkedList * ll){
    ll->head = NULL;

}

Node * createNode(int data){
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data  = data;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(LinkedList * ll,int data){
    Node * newNode = createNode(data);
    newNode->next = ll->head;
    ll->head = newNode;

}

void insertLast(LinkedList * ll,int data){
    if(ll->head == NULL){
        insertFirst(ll,data);
        return;

    }

    Node * temp = ll->head;
    Node * newNode = createNode(data);

    while(temp->next != NULL){
        temp= temp->next;
    }

    temp->next = newNode;

}


// i am assuming index start from 1
void insert(LinkedList * ll ,int data,int index){
    if(index == 1){
        insertFirst(ll,data);
        return;
    }
    Node * newNode = createNode(data);
    Node * temp = ll->head;
    // am assuming it not going out of the range so here i am not going to check the null
    for(int i =1;i<index-1;i++){
        temp = temp->next;
    }

    Node * next = temp->next;
    temp->next = newNode;
    newNode->next = next;
}

void deleteFirst(LinkedList * ll){
    if(ll->head == NULL){
        printf("Linked list is empty");
        return;
    }
    
    Node * newHead = ll->head->next;
    Node * del = ll->head;
    ll->head = newHead;
    free(del);

}



int main(){

}