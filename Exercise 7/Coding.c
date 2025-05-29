#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int urgency;
} Patient;

typedef struct {
    Patient *data;
    int size, capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->data = (Patient*)malloc(capacity * sizeof(Patient));
    return pq;
}

void displayQueue(PriorityQueue* pq) {
    int i;
    printf("Queue: ");
    for (i = 0; i < pq->size; i++) {
        printf("[%s, %d] ", pq->data[i].name, pq->data[i].urgency);
    }
    printf("\n");
}

void insertPatient(PriorityQueue* pq, char* name, int urgency) {
    if (pq->size == pq->capacity) return;
    int i = pq->size - 1;
    while (i >= 0 && pq->data[i].urgency < urgency) {
        pq->data[i + 1] = pq->data[i];
        i--;
    }
    strcpy(pq->data[i + 1].name, name);
    pq->data[i + 1].urgency = urgency;
    pq->size++;
    displayQueue(pq);
}

void treatPatient(PriorityQueue* pq) {
    if (pq->size == 0) return;
    printf("Patient %s with urgency %d treated\n", pq->data[0].name, pq->data[0].urgency);
    for (int i = 1; i < pq->size; i++) {
        pq->data[i - 1] = pq->data[i];
    }
    pq->size--;
    displayQueue(pq);
}

int main() {
    PriorityQueue* pq = createPriorityQueue(10);

    insertPatient(pq, "Alice", 7);
    insertPatient(pq, "Bob", 9);
    insertPatient(pq, "Charlie", 5);
    insertPatient(pq, "Diana", 10);

    treatPatient(pq);
    treatPatient(pq);

    free(pq->data);
    free(pq);
    return 0;
}