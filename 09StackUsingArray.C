#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    int *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == -ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 void  Push(struct stack*ptr,int value){
     if(isFull(ptr)){
         printf("Stack Overflow");
     }
     else{
    ptr->top++;
    ptr->arr[ptr->top]=value;
   
   
     }
    
}
 void Pop(struct stack*ptr,int value){
     if(isEmpty(ptr)){
         printf("Stack Empty");
     }
     else{
         int value=ptr->arr[ptr->top];
    ptr->top--;
    ptr->top=ptr->top-1;
    printf(" stack elementPoped :%d",value);
   
     }
    
}
 int Peek(struct stack*s,int i){
    int Arrindex=s->top-i+1;
    if (Arrindex<0){
        printf("invalid position");
    }
   
      
        return s->arr[Arrindex];
    
    
}
int stackTop(struct stack*s){
    return s->arr[s->top];
}
int stackBottom(struct stack*s){
    return s->arr[0];
}
 
 
int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));
 
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    int value;
      
       // Check if stack is empty
   
       Push(s,10);
       Push(s,20);
       Push(s,30);
       Push(s,40);
       Push(s,50);
           // Printing values from the stack
    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at position %d is %d\n",j, Peek(s, j));
    }
    printf("Top value of the stack %d\n",stackTop(s));
    printf("bottom value of the stack %d\n",stackBottom(s));

    return 0;
}
