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
// Queue using 2 stacks (costly pop)
struct Queue2 {
    struct Stack s1, s2;
};

void initQueue2(struct Queue2* q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

// Push is easy
void enqueue2(struct Queue2* q, int x) {
    push(&q->s1, x);
    printf("Enqueued %d\n", x);
}

// Costly Pop
int dequeue2(struct Queue2* q) {
    if (isEmpty(&q->s1) && isEmpty(&q->s2)) {
        printf("Queue is Empty!\n");
        return -1;
    }

    // Move from s1 to s2 if s2 is empty
    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}
int main() {
        printf("Method 2: Costly Pop\n");
    struct Queue2 q2;
    initQueue2(&q2);
    enqueue2(&q2, 100);
    enqueue2(&q2, 200);
    enqueue2(&q2, 300);
    printf("Dequeued: %d\n", dequeue2(&q2));
    printf("Dequeued: %d\n", dequeue2(&q2));

    return 0;
}
