#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10000

typedef int element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ �Լ�
void init(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		return -1;
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

// ���� �Լ�
element front(QueueType* q)
{
	if (is_empty(q))
		return -1;
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}
element back(QueueType* q)
{
	if (is_empty(q))
		return -1;
	return q->queue[(q->rear) % MAX_QUEUE_SIZE];
}

int get_size(QueueType* q)
{
	int cnt;

	cnt = q->rear - q->front;
	if (cnt < 0)
		cnt = cnt + MAX_QUEUE_SIZE;

	return cnt;
}

int main(void)
{
	QueueType q;
	int n, i, pushN;
	char str[10];

	init(&q);

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", str);

		if (strcmp(str, "push") == 0) {
			scanf("%d", &pushN);
			enqueue(&q, pushN);
		}
		else if (strcmp(str, "pop") == 0)
			printf("%d\n", dequeue(&q));
		else if (strcmp(str, "size") == 0)
			printf("%d\n", get_size(&q));
		else if (strcmp(str, "empty") == 0) {
			if (!is_empty(&q))
				printf("0\n");
			else
				printf("1\n");
		}
		else if (strcmp(str, "front") == 0)
			printf("%d\n", front(&q));
		else if (strcmp(str, "back") == 0)
			printf("%d\n", back(&q));
	}
}