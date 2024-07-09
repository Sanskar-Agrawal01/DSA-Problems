#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

char isEmpty(struct stack *ptr)
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
    if (ptr->top == ptr->size - 1)
    { // Corrected the condition
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char Pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return '\0'; // Return a null character if stack is empty
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value; // Correctly return the popped value
    }
}



char stackTop(struct stack*s){
    return s->arr[s->top];
}
int precedence(char ch){
    if(ch =='*' || ch=='/'){
        return 3;
    }
    if(ch =='+' || ch=='-'){
        return 2;
    }
    return 0;
}
int isOperator(char ch){
    if(ch=='+'|| ch=='-'|| ch=='/'|| ch=='*'){
        return 1;

    }
    
        return 0;
    
}
char *InfixToPostfix(char *infix){
struct stack*s=(struct stack*)malloc(sizeof(struct stack));
s->size=100;
s->top=-1;
s->arr=(char*)malloc(s->size*sizeof(char));
char*Postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
int i=0;
int j=0;
while(infix[i]!='\0'){
    if(!isOperator(infix[i])){
        Postfix[j]=infix[i];
        i++;
        j++;
    }
    else if(precedence(infix[i])>precedence(stackTop(s))) {
        Push(s,infix[i]);
        i++;

    }
    else{
        Postfix[j]=Pop(s);
        j++;
    }
}

while (!isEmpty(s))
{
    Postfix[j]=Pop(s);
    j++;
}
Postfix[j]='\0';
return Postfix;
}





int main()
{
    char *infix = "a-b/z*d";
    printf("Postfix to Infix:%s\n",InfixToPostfix(infix));

    return 0;
}
