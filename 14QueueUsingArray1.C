#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int f;
    int r;
    int*arr;
};
int isFull(struct Queue*q){
    if(q->r==q->size-1){
        printf("Queue overflow");
    }
    else{
        printf("Queue is not full");
    }
    return 0;
}
int isEmpty(struct Queue *q){
    if(q->f==q->r){
        printf("Queue Overdriven");
    }
    else{
        printf("Queue is not Empty");
    }
    return 0;
}
int EnQueue(struct  Queue*q,int value){
    if(isFull(q)){
        printf("Queue OverFlow");
    }
    else{
        q->r=q->r+1;
        q->arr[q->r]=value;
    }
    return value;
}
int DeQueue(struct Queue *q){
    int a=-1;
    if(isEmpty(q)){
        return 0;
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
int main(){
    struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
    q->size=10;
    q->f=-1;
    q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));
   int i= EnQueue(q,10);
    printf("element 1:%d\n",i);
    printf("Dequeueing element :%d\n",DeQueue(q));
    printf("Dequeueing element :%d\n",DeQueue(q));
  
    
    return 0;
}