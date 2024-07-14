#include <stdio.h>
#include <stdlib.h>
 struct Node*f=NULL;
    struct Node*r=NULL;

struct Node
{
    int data;

    
    struct Node* next;
};
void  linkedtraversal(struct Node*ptr){
    printf("Printing Elemnts of Queue\n");
while(ptr !=NULL){
    printf("Element :%d\n",ptr->data);
    ptr=ptr->next;
}
}
void EnQueue(int value){
    struct Node*n=(struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue FUll");

    }
    else{
        n->data=value;
        n->next=NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
   
}
int DeQueue(){
    struct Node*ptr=f;
    if(f==NULL){
       printf("Queue Empty");
    }
    else{
        f=f->next;
        int value=ptr->data;
        free(ptr);
          return value;
    }
  
}


int main()
{
   
    
  linkedtraversal(f);
  EnQueue(10);
  EnQueue(20);
  EnQueue(30);
  EnQueue(40);
  linkedtraversal(f);
  DeQueue();
    DeQueue();
      DeQueue();
        DeQueue();
          DeQueue();
   linkedtraversal(f);

    

    

 
    return 0;
}