#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int top;
    int arr[MAX];
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return (s->top == -1);
}

// Check if stack is full
int isFull(struct Stack* s) {
    return (s->top == MAX - 1);
}

// Push element
void push(struct Stack* s, int x) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++s->top] = x;
}

// Pop element
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Peek element
int peek(struct Stack* s) {
    if (isEmpty(s)) return -1;
    return s->arr[s->top];
}
// Queue using 2 stacks (costly push)
struct Queue1 {
    struct Stack s1, s2;
};

void initQueue1(struct Queue1* q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

// Costly Push
void enqueue1(struct Queue1* q, int x) {
    // Move all from s1 to s2
    while (!isEmpty(&q->s1)) {
        push(&q->s2, pop(&q->s1));
    }

    // Push new element to s1
    push(&q->s1, x);

    // Move everything back to s1
    while (!isEmpty(&q->s2)) {
        push(&q->s1, pop(&q->s2));
    }

    printf("Enqueued %d\n", x);
}

// Pop is easy
int dequeue1(struct Queue1* q) {
    if (isEmpty(&q->s1)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    return pop(&q->s1);
}
int main() {
    printf("Method 1: Costly Push \n");
    struct Queue1 q1;
    initQueue1(&q1);
    enqueue1(&q1, 10);
    enqueue1(&q1, 20);
    enqueue1(&q1, 30);
    printf("Dequeued: %d\n", dequeue1(&q1));
    printf("Dequeued: %d\n", dequeue1(&q1));
    return 0;
}
