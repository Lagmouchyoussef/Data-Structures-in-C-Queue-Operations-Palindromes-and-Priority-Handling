#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->data = (int*)malloc(capacity * sizeof(int));
    return q;
}

int isQueueEmpty(Queue* q) {
    return q->size == 0;
}

int isQueueFull(Queue* q) {
    return q->size == q->capacity;
}

void enqueue(Queue* q, int value) {
    if (isQueueFull(q)) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) return -1;
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return value;
}

void displayQueue(Queue* q) {
    int i, idx;
    for (i = 0, idx = q->front; i < q->size; i++) {
        printf("%d ", q->data[idx]);
        idx = (idx + 1) % q->capacity;
    }
    printf("\n");
}

typedef struct {
    int *data;
    int top, capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->capacity = capacity;
    s->top = -1;
    s->data = (int*)malloc(capacity * sizeof(int));
    return s;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (s->top == s->capacity - 1) return;
    s->data[++s->top] = value;
}

int pop(Stack* s) {
    if (isStackEmpty(s)) return -1;
    return s->data[s->top--];
}

void reverseQueue(Queue* q) {
    Stack* s = createStack(q->capacity);
    while (!isQueueEmpty(q)) {
        push(s, dequeue(q));
    }
    while (!isStackEmpty(s)) {
        enqueue(q, pop(s));
    }
    free(s->data);
    free(s);
}

int main() {
    Queue* q = createQueue(10);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    printf("Original queue: ");
    displayQueue(q);

    reverseQueue(q);

    printf("Reversed queue: ");
    displayQueue(q);

    free(q->data);
    free(q);
    return 0;
}