#include<stdio.h>

#define QUEUE_SIZE 10

typedef struct{
	int items[QUEUE_SIZE];
	int rear, front;
	int size;
}queue;

typedef enum{true=1,false=0}boolean;

void init(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
boolean isEmpty(queue *q);
boolean isFull(queue *q);
int increment(int x);
void display(queue *q);

int main(){
	queue q;
	init(&q);
	int i,n;
	for(i=0;i<6;i++){
		printf("Enter element %d:",i+1);
		scanf("%d",&n);
		enqueue(&q,n);
	}
	display(&q);
	printf("\nDeleted element: %d\n",dequeue(&q));
	printf("\nDeleted element: %d\n",dequeue(&q));
	for(i=0;i<5;i++){
		printf("Enter element %d:",i+1);
		scanf("%d",&n);
		enqueue(&q,n);
	}
	display(&q);
}

void init(queue *q){
	q->front = 0;
	q->rear = -1;
	q->size = 0;	
}

void enqueue(queue *q, int x){
	if(isFull(q))
		printf("Queue is full\n");
	else{
		q->rear = increment(q->rear);
		q->items[q->rear] = x;
		q->size++;
	}
}

int dequeue(queue *q){
	if(isEmpty(q)){	
		printf("Queue is empty\n");
		return 0;
	}else{
		int x = q->items[q->front];
		q->front = increment(q->front);
		q->size--;
		return x;
	}
}

boolean isEmpty(queue *q){
	if(q->size==0)
		return true;
	else
		return false;
}

boolean isFull(queue *q){
	if(q->size==QUEUE_SIZE)
		return true;
	else
		return false;
}

int increment(int x){
	if(++x==QUEUE_SIZE)
		x=0;
	return x;
}
void display(queue *q){
	int i;
	printf("\nQueue Elements: ");
	i=q->front;
	while(i!=q->rear){
		printf("%d\t",q->items[i]);
		i=increment(i);
	}
	printf("%d\t",q->items[i]);
}
