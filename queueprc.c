#include<stdio.h>
#include<stdlib.h>

struct queue 
{
    int rear;
    int front;
    int*arr;
    int size;
};
void enqueue(struct queue* q , int n)
{
    if ( q-> rear == q->size - 1)
    {
        printf("Queue full\n");
    }
    else{
         q -> rear++;
    q-> arr[q -> rear] =n;
    q-> front = 0;
    }
}
 int dequeue(struct queue * q)
 {
    if(q -> front == q->rear)
    {
        printf("Queue Empty\n");
        return -1;
    }
    q -> front = (q->front +1)%q->size ;
    int item  = q -> arr[q->front];
    return item;
 }
 void display ( struct queue* q )
 {
    if ((q->rear +1)%q->size == q->front)
    {
        printf("Queue Empty");
        return;
    }
    for (int i = q->front; i <= q-> rear; i=(i+1)%q->size)
    {
        printf("%d",q->arr[i]);
        printf("\n");
    }
 }
 int main()
 {
    struct queue* que = (struct queue*)malloc (sizeof(struct queue));
    int num;
    printf("Enter size\n");
    scanf("%d",&num);
    que -> size = num;
    que -> rear = -1;
    que -> front = -1;
    que -> arr = (int *)malloc(num * sizeof(int));
    int choice,val;
    do
    {
        /* code */
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1:
            {
                printf("Enter val\n");
                scanf("%d",&val);
                enqueue(que,val);
                break;
            }
            case 2:
            {
                int temp = dequeue(que);
                printf("%d\n",temp);
                break;
            }
            case 3:
            {
                display(que);
                break;
            }
            case 4:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    } while (choice!=4);
    return 0;
 }