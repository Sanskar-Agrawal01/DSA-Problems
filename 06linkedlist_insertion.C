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
// CASE 1: Insertion at head of the linked list
struct Node *linkedlistinsertion(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
// CASE 2: Insertion at a given Index  of the linked list
struct Node *insertionatindex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// CASE 3: Insertion at End of the linked list
struct Node *insertionend(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return ptr;
}
// CASE 4: Insertion at a given previous of the linked list
struct Node *insertionPreNode(struct Node *head, int data, struct Node *PreNode)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
   ptr->next=PreNode->next;
   PreNode->next=ptr;

    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    linkedtraversal(head);
    // head = linkedlistinsertion(head, 50);
    // linkedtraversal(head);
    // head = insertionatindex(head, 70, 3);
    // head=insertionend(head,48);
    head=insertionPreNode(head,45,second);
    linkedtraversal(head);

    return 0;
}