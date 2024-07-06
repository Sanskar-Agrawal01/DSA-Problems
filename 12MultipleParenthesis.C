#include <stdio.h>
#include <stdlib.h>

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
int match(char a, char b)
{
    
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}

int MultipleParenthesisMatch(char * exp){
    // Create and initialize the stack
    struct stack* s=(struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    char popped_ch;
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            Push(s, exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']'){
            if(isEmpty(s)){
                return 0;
            }
            popped_ch = Pop(s);
            if(!match(popped_ch, exp[i])){ 
              return 0;  
            }
        }
    }
 
    if(isEmpty(s)){
        return 1;
    }
    else{
        return 0;
    }
}





int main()
{
    char *exp = "[(2*4)}-(2-5)]";

    if (MultipleParenthesisMatch(exp))
    {
        printf("Parentheses are balanced\n");
    }
    else
    {
        printf("Parentheses are not balanced\n");
    }

    return 0;
}
