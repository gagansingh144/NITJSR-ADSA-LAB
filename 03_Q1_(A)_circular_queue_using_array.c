#include<stdio.h>
#include<stdlib.h>
#define MAX 5
 int queue[MAX];
    int front=-1;
    int rear=-1;
void enqueue(int x)
{
    if(rear==MAX-1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear++;
        queue[rear]=x;
        printf("Inserted %d\n",x);
    }
}
void dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted %d\n",queue[front]);
        front++;
    }
}
void display()
{
    if(front==-1 || front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
}
