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

int main() {
    Queue* q = createQueue(10);

    enqueue(q, 101);
    enqueue(q, 102);
    enqueue(q, 103);

    printf("Queue: ");
    displayQueue(q);

    while (!isQueueEmpty(q)) {
        int client = dequeue(q);
        printf("Client %d served\n", client);
        printf("Queue: ");
        displayQueue(q);
    }

    free(q->data);
    free(q);
    return 0;
}