#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node *next;
};
typedef struct {
   struct node* rear;
    struct node* front;
    int size;
    int count;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
MyCircularQueue* q = malloc(sizeof(MyCircularQueue));
q->front = NULL;
q->rear = NULL;
q->size  = k;
q->count = 0;
return q;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if (obj->count == obj->size) return false;
    if(obj->rear==NULL && obj->front==NULL){
    obj->rear=newnode;
    obj->front=newnode;
    newnode->next=newnode;
    }
    else{
        obj->rear->next=newnode;
        obj->rear=newnode;
        newnode->next=obj->front;
    }
obj->count++;
return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->count == 0) return false;
    struct node *temp;
    temp=obj->front;
    if(obj->front==NULL ){
        return false;
    }
    else if(obj->front==obj->rear){
        obj->front=NULL;
        obj->rear=NULL;
    }
    else{
        obj->front=obj->front->next;
        obj->rear->next=obj->front;
    }
    free(temp);
    obj->count--;
    return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->count == 0) return -1;
    return obj->front->data;
}

int myCircularQueueRear(MyCircularQueue* obj) {
     if(obj->count==0) {
        return -1;
    }
    return obj->rear->data;

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->count==0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->count==obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(!obj) return;
    if(obj->front!=NULL){
        struct node *temp;
        temp=obj->front;
        struct node *next;
    
    do{
        next=temp->next;
        free(temp);
        temp=next;
    }while(temp!=obj->front);
}
free(obj);
}
/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/