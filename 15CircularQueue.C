#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int* arr;
};
int isFull(struct Queue *q) {
    if ((q->r + 1) % q->size == q->f) {
        return 1;
    } else {
        return 0;
    }
    return 0;
}

int isEmpty(struct Queue *q) {
    if (q->f == q->r) {
        return 1;
    } else {
        return 0;
    }
    return 0;
}

void EnQueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
    } else {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = value;
    }
}

int DeQueue(struct Queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
    } else {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main() {
    struct Queue *q = (struct Queue*) malloc(sizeof(struct Queue));
    q->size = 3;  // Need extra space to differentiate full/empty
    q->f = 0;
    q->r = 0;
    q->arr = (int*) malloc(q->size * sizeof(int));

    EnQueue(q, 10);
    EnQueue(q, 20);
    EnQueue(q, 30);  // This will cause overflow

    printf("Dequeueing element: %d\n", DeQueue(q));
    printf("Dequeueing element: %d\n", DeQueue(q));
    printf("Dequeueing element: %d\n", DeQueue(q));  // This will cause underflow

    // Clean up
   

    return 0;
}
