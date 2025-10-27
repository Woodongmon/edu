/*
 ============================================================================
 Name        : test_queue.c
 Author      : 123
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#define MAX_QUEUE_SIZE	5

typedef struct
{
	int data[MAX_QUEUE_SIZE];	// 큐 사이즈 크기 배열
	int front,rear;				// 큐 전방 / 후방
}queueType;

void init_queue(queueType *q)
{
	q->front= q->rear-1;	//배열 인덱스가 0이므로 queue가 비어있다면, 둘다 -1
}

//큐이 비어있는지 확인
bool is_empty(queueType *q)
{
	return (q->front == q->rear);

}

//큐가 차있는지 확인
int is_full(queueType *q)
{
	return (q->rear == MAX_QUEUE_SIZE-1);
}

void enqueue(queueType *q, int data)
{
	if(is_full(q))
		{
		printf("queue is full\n\r");
		}
	else
	{
		q->data[++(q->rear)] = data;
	}

}


//큐 확인 후 삭제 연산

int dequeue(queueType *q)
{
	if (is_empty(q))
	{
		printf("queue is full\n\r");
		exit(1); //프로그램 종료 함수
	}
	int data = q->data[(q->front)];
	return data;
}


void print_queue(queueType *q)
{
	if(is_empty(q))
	{
		printf("Empty queue\n\r");
	}
	else
	{
		printf("queue:");
		for(int i=0; i< MAX_QUEUE_SIZE; i++)
		{
			if(i <= q-> front || i > q->rear)
		{
				printf(" |");
		}
		else
		{
	    printf("%d|", q->data[i]);
		}
	} printf("\n");
}
}

int main(void)
{
	queueType queue;

	int item = 0;
	init_queue(&queue);

	enqueue(&queue,3);
	print_queue(&queue);

	enqueue(&queue,4);
	print_queue(&queue);

	enqueue(&queue,5);
	print_queue(&queue);

	item = dequeue(&queue);
	print_queue(&queue);

	enqueue(&queue, 6);
	print_queue(&queue);

	item=dequeue(&queue);
	print_queue(&queue);


	return 0;
}

