#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return (q->front == -1);
}

void enqueue(Queue *q, int x) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = x;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return val;
}

typedef struct {
    Queue q1, q2;
} Stack;

void initStack(Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(Stack *s, int x) {
    enqueue(&s->q2, x);
    while (!isEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    // swap q1 and q2
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue(&s->q1);
}

int main() {
    Stack s;
    initStack(&s);

    printf("Stack using two queues (Costly Push):\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    return 0;
}
