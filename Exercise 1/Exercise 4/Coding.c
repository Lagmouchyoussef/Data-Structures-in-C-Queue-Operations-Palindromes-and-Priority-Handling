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

Queue* mergeQueues(Queue* q1, Queue* q2) {
    Queue* merged = createQueue(q1->size + q2->size);
    int i, idx;
    for (i = 0, idx = q1->front; i < q1->size; i++) {
        enqueue(merged, q1->data[idx]);
        idx = (idx + 1) % q1->capacity;
    }
    for (i = 0, idx = q2->front; i < q2->size; i++) {
        enqueue(merged, q2->data[idx]);
        idx = (idx + 1) % q2->capacity;
    }
    return merged;
}

int main() {
    Queue* q1 = createQueue(10);
    Queue* q2 = createQueue(10);

    enqueue(q1, 1);
    enqueue(q1, 3);

    enqueue(q2, 2);
    enqueue(q2, 4);

    printf("Queue 1: ");
    displayQueue(q1);

    printf("Queue 2: ");
    displayQueue(q2);

    Queue* merged = mergeQueues(q1, q2);

    printf("Merged queue: ");
    displayQueue(merged);

    free(q1->data); free(q1);
    free(q2->data); free(q2);
    free(merged->data); free(merged);
    return 0;
}