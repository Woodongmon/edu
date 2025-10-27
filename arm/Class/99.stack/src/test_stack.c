/*
 ============================================================================
 Name        : test_stack.c
 Author      : 123
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#define MAX_STACK_SIZE	5

typedef struct
{
	int data[MAX_STACK_SIZE];	// 스텍 사이즈 크기 배열
	int top;					// 스텍 상단 / 배열은 0부터 시작
}stackType;

void init_stack(stackType *s)
{
	s->top= -1;
}

//스텍이 비어있는지 확인
bool is_empty(stackType *s)
{
	return (s->top==-1);

}

//스택이 꽉 차있는지 확인
int is_full(stackType *s)
{
	return (s->top == MAX_STACK_SIZE);
}

void push(stackType *s, int data)
{
	if(is_full(s))
		{
		printf("stack is full\n\r");
		}
	else
	{
		s->data[++(s->top)] = data;
	}

}


//스텍 확인 후 삭제 연산

int pop(stackType *s)
{
	if (is_empty(s))
	{
		printf("stack is full\n\r");
		exit(1); //프로그램 종료 함수
	}
	else
	{
		int data = s->data[(s->top)--];
		return data;
	}
}



void print_stack(stackType *s)
{
	if(is_empty(s))
	{
		printf("Empty Stack\n\r");
	}
	else
	{
		printf("stack:");
		for(int i=0; i< s->top; i++)
		{
			printf("%d|",s->data[i]);
		}
	    printf("%d\n", s->data[s->top]);

	}
}

int main(void)
{
	stackType stack;

	init_stack(&stack);

	push(&stack,7);
	print_stack(&stack);

	push(&stack,8);
	print_stack(&stack);

	return 0;
}

