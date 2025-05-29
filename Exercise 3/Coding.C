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

int areQueuesIdentical(Queue* q1, Queue* q2) {
    if (q1->size != q2->size) return 0;
    int i, idx1 = q1->front, idx2 = q2->front;
    for (i = 0; i < q1->size; i++) {
        if (q1->data[idx1] != q2->data[idx2]) return 0;
        idx1 = (idx1 + 1) % q1->capacity;
        idx2 = (idx2 + 1) % q2->capacity;
    }
    return 1;
}

void displayQueue(Queue* q) {
    int i, idx;
    for (i = 0, idx = q->front; i < q->size; i++) {
        printf("%d ", q->data[idx]);
        idx = (idx + 1) % q->capacity;
    }
    printf("\n");
}

int main() {
    Queue* q1 = createQueue(10);
    Queue* q2 = createQueue(10);
    Queue* q3 = createQueue(10);

    enqueue(q1, 1); enqueue(q1, 2); enqueue(q1, 3);
    enqueue(q2, 1); enqueue(q2, 2); enqueue(q2, 3);
    enqueue(q3, 1); enqueue(q3, 2); enqueue(q3, 4);

    printf("Queue 1: "); displayQueue(q1);
    printf("Queue 2: "); displayQueue(q2);
    printf("Queue 3: "); displayQueue(q3);

    if (areQueuesIdentical(q1, q2))
        printf("Queue 1 and Queue 2 are identical.\n");
    else
        printf("Queue 1 and Queue 2 are not identical.\n");

    if (areQueuesIdentical(q1, q3))
        printf("Queue 1 and Queue 3 are identical.\n");
    else
        printf("Queue 1 and Queue 3 are not identical.\n");

    free(q1->data); free(q1);
    free(q2->data); free(q2);
    free(q3->data); free(q3);
    return 0;
}