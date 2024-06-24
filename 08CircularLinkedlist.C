#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;

    struct Node *next;
};

void linkedtraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {

        printf("Elements : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
struct Node *InsertionAtStart(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
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
    fourth->next = head;

    linkedtraversal(head);

    head = InsertionAtStart(head, 60);
    linkedtraversal(head);
    return 0;
}