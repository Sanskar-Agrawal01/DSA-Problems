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
// CASE 1: deletion At Start
struct Node *deletionAtStart(struct Node *head, int data)
{
    struct Node *ptr = head;

    head = head->next;
    free(ptr);
    return head;
}
// CASE 2: deletion At a given index
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}
// CASE 3: deletion At End
struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}
// CASE 4: deletion At a given value of a node
struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL && q->data != value)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}
struct Node *Reversal(struct Node *fourth)
{
    struct Node *p = fourth;
    struct Node *q = fourth->next;
    while (q!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->next == head)
    {
       head->next=NULL;
    }

    return fourth;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    int index;
    int value;

        head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    linkedtraversal(head);
   
    // printf("After deletion at front");
    // head = deletionAtStart(head);
    // linkedtraversal(head);
    // printf("After deletion at index:\n");
    // head = deleteAtIndex(head, 1);
    // linkedtraversal(head);
    // printf("After deletion at value: \n");
    // head = deleteAtValue(head, 20);
    // linkedtraversal(head);
     head = Reversal(fourth);
     linkedtraversal(head);

    return 0;
}