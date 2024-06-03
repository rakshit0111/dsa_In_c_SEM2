#include <stdio.h>
#include <stdlib.h>

struct Circular
{
  int *items;
  int front, rear;
  int size;
};

int isFull(struct Circular *queue)
{
  if ((queue->front == 0 && queue->rear == queue->size - 1) ||
      (queue->front == queue->rear + 1))
  {
    return 1;
  }
  return 0;
}

int isEmpty(struct Circular *queue)
{
  if (queue->front == -1)
  {
    return 1;
  }
  return 0;
}

void enqueue(struct Circular *queue, int value)
{
  if (isFull(queue))
  {
    printf("Queue is full\n");
  }
  else
  {
    if (queue->front == -1)
    {
      queue->front = 0;
    }
    queue->rear = (queue->rear + 1)% queue->size;
    queue->items[queue->rear] = value;
    printf("%d enqueued to queue\n", value);
  }
}

void dequeue(struct Circular *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty\n");
  }
  else
  {
    int removedValue = queue->items[queue->front];
    printf("%d dequeued from queue\n", removedValue);
    if (queue->front == queue->rear)
    {
      queue->front = -1;
      queue->rear = -1;
    }
    else
    {
      queue->front = (queue->front + 1) % queue->size;
    }
  }
}

void display(struct Circular *queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty\n");
  }
  else
  {
    int i;
    if (queue->front <= queue->rear)
    {
      for (i = queue->front; i <= queue->rear; i++)
      {
        printf("%d ", queue->items[i]);
      }
    }
    else
    {
      for (i = queue->front; i < queue->size; i++)
      {
        printf("%d ", queue->items[i]);
      }
      for (i = 0; i <= queue->rear; i++)
      {
        printf("%d ", queue->items[i]);
      }
    }
    printf("\n");
  }
}

int main()
{
  struct Circular *queue = (struct Circular *)malloc(sizeof(struct Circular));
  queue->front = -1;
  queue->rear = -1;
  queue->size = 5;
  queue->items = (int *)malloc(queue->size * sizeof(int));

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  display(queue);

  dequeue(queue);
  display(queue);

  enqueue(queue, 50);
  enqueue(queue, 60);
  display(queue);

  return 0;
}