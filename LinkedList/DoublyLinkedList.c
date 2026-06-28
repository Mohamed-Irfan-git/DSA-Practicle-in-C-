#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;

}Node;

typedef struct LinkedList {
    Node * head;
    Node * tail;
}LinkedList;

void init(LinkedList * ll){
    ll->head = NULL;
    ll->tail = NULL;
}

Node * createNode(int data){
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data  = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertFirst(LinkedList * ll,int data){
    if(ll->head == NULL){
        Node * newNode = createNode(data);
        ll->head = newNode;
        ll->tail = ll->head;
        return;
    }
    Node * newNode = createNode(data);
    newNode->next = ll->head;
    ll->head->prev = newNode;
    ll->head = newNode;

}

void insertLast(LinkedList * ll,int data){
    if(ll->head == NULL){
        insertFirst(ll,data);
        return;

    }

    
    Node * newNode = createNode(data);
    newNode->prev = ll->tail;
    ll->tail->next = newNode;
    ll->tail = newNode;


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
    for(int i =1;i<index;i++){
        temp = temp->next;
    }

    Node * prev = temp->prev;
    newNode->prev = prev;
    newNode->next = temp;

    prev->next = newNode;
    temp->prev = newNode;
}

void deleteFirst(LinkedList * ll){
    if(ll->head == NULL){
        printf("Linked list is empty");
        return;
    }
    
    Node * newHead = ll->head->next;
    Node * del = ll->head;
    ll->head = newHead;

    if(newHead != NULL)
        newHead->prev = NULL;
    else
        ll->tail = NULL;

    free(del);

}




void deleteLast(LinkedList * ll){
    if(ll->head == NULL){
        printf("linked list is empty");
        return;

    }
    if(ll->head->next == NULL){
        deleteFirst(ll);
        return;
    }

    Node * del = ll->tail;
    ll->tail = ll->tail->prev;
    ll->tail->next = NULL;
    free(del);
}


void delete(LinkedList * ll,int index){
    // i am assuming this is one based index
    if(index==1){
        deleteFirst(ll);
        return;
    }

    Node * temp = ll->head;
    for(int i =1;i < index;i++){
        temp = temp->next;
    }

    if(temp == ll->tail){
        deleteLast(ll);
        return;
    }

    Node * prev = temp->prev;
    Node * next = temp->next;

    prev->next = next;
    next->prev = prev;
    

    Node * del = temp;
    free(del);

}



int main(){

}