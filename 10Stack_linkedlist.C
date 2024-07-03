#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;

    struct Node *next;
};

void linkedtraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element :%d\n", ptr->data);
        ptr = ptr->next;
    }
}
 int isEmpty(struct Node*top){
    
    if(top==NULL){
        printf("Stack is Empty");
        return 1;
    }
    else{
        return 0;
    }
 }
  int isFull(struct Node*ptr){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Stack overflow");
        return 1;
    }
    else{
        return 0;
    }
 }
struct Node* Push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int Pop(struct Node**top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}
int stackTop(struct Node**top){
    return (*top)->data;
}
int peek(struct Node*top,int pos ){
    struct Node*ptr=top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return 0;
    }
}

int main()
{
    struct Node *top=NULL;
   top= Push(top,40);
   top=  Push(top,30);
      top=Push(top,20);
      top= Push(top,10);
    

    printf("After Push Operation \n");
    
    linkedtraversal(top);
   
    //  int element = Pop(&top);
    // printf("Popped element is %d\n", element);
    // linkedtraversal(top);
    // int  s_top= stackTop(&top);
    // printf("top element",s_top);
  printf("Value at 1 is %d",peek(top,1));


    return 0;
}