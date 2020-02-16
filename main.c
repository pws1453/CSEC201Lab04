/*
 * Author:
 */
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct LinkList {
    int size;
    struct Node* head;
};

struct LinkList *makeList() {
    struct LinkList *retList = (struct LinkList*)malloc(sizeof(struct LinkList));
    retList->size = 0;
    retList->head = NULL;
    return retList;
}

void Add(struct LinkList *curList,int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next=curList->head;
    curList->head = newnode;
    curList->size = curList->size +1;
}

void Delete(struct LinkList *curList,int data){
    struct Node* first = curList->head;
    if (first != NULL && first->data == data){
        curList->head = first->next;
    }
    while (first->next != NULL){
        if (first->next->data == data){
            first->next = first->next->next;
        }
        first = first->next;
    }
}

void Print(struct LinkList* curList){
    struct Node* first = curList->head;
    while (first!= NULL){
        printf("%d ",first->data);
        first = first->next;
    }
    printf("\n");
}


void update(struct LinkList* curList, int position, int data){
    struct Node* first = curList->head;
    for (int i = 0; i < position; i++) {
        first=first->next;
    }
    first->data = data;
}

void delete2(struct LinkList* curList, int position){
    struct Node* first = curList->head;
    if (position == 0){
        curList->head = first->next;
    }
    else{
        for (int i = 0; i <position-1 ; i++) {
            first = first->next;
        }
        first->next = first->next->next;
    }
}

struct Node* insertForInsort(int value, struct Node* node){
    if (node == NULL){
        struct Node *retNode = (struct Node*)malloc(sizeof(struct Node*));
        retNode->data = value;
        retNode->next=NULL;
        return retNode;
    } else if (node->data < value){
        struct Node *retNode = (struct Node*)malloc(sizeof(struct Node*));
        retNode->data = value;
        retNode->next = node;
        return retNode;
    } else{
        struct Node *retNode = (struct Node*)malloc(sizeof(struct Node*));
        retNode->data = node->data;
        retNode->next = insertForInsort(value,node->next);
        return retNode;
    }
}


struct Node* sort(struct Node* headNode){
    if (headNode == NULL){
        return NULL;
    }
    struct Node* sorted_node = (struct Node*)malloc(sizeof(struct Node*));
    sorted_node->data = headNode->data;
    sorted_node->next = NULL;
    headNode = headNode->next;
    while (headNode != NULL){
        sorted_node = insertForInsort(headNode->data,sorted_node);
        headNode = headNode->next;
    }
    return sorted_node;
}

void printOldestFirst(struct LinkList* curList){
    if (curList->head == NULL){
        return;
    }
    struct LinkList *retList = (struct LinkList*)malloc(sizeof(struct LinkList));
    retList->head = curList->head->next;
    retList->size = curList->size -1;
    printOldestFirst(retList);
    printf("%d ",curList->head->data);
}

int main() {
    struct LinkList *newList = makeList();
    Add(newList,1);
    Add(newList,2);
    Add(newList,3);
    Add(newList,4);
    Add(newList,5);
    Add(newList,6);
    Add(newList,7);
    Delete(newList,2);
    update(newList,1,20);
    Print(newList);
    delete2(newList,2);
    Print(newList);
    newList->head = sort(newList->head);
    Print(newList);
    printOldestFirst(newList);
    return 0;
}
