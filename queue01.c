#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

typedef int element;
typedef struct QNode
{
	element data;
	struct QNode *link;
}QNode;

typedef struct
{
	QNode *front;
	QNode *back;
}LQueueType;

LQueueType *createLinkedQueue()
{
	LQueueType *LQ;
	LQ = (LQueueType *)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->back = NULL;
	return LQ;
}

int Empty(LQueueType *LQ)
{
	if (LQ->front == NULL)
	{
		return 1;
	}
	else return 0;
}

void enQueue(LQueueType *LQ, element item)
{
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL)
	{
		LQ->front = newNode;
		LQ->back = newNode;
	}
	else
	{
		LQ->back->link = newNode;
		LQ->back = newNode;

	}
}

element deQueue(LQueueType *LQ)
{
	QNode *old = LQ->front;
	element item;
	if (LQ->front == NULL)
	{
		return -1;
	}
	else
	{
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
		{
			LQ->back = NULL;
		}
			free(old);
			return item;
		
	}
}

element Front(LQueueType *LQ)
{
	element item;
	if (Empty(LQ))
	{
		return 0;
	}
	else
	{
		item = LQ->front->data;
		return item;

	}

}

element Back(LQueueType *LQ)
{
	element item;
	if (Empty(LQ))
	{
		return 0;
	}
	else
	{
		item = LQ->back->data;
		return item;

	}

}


int main()
{
	LQueueType *LQ = createLinkedQueue();
	element data;
	int i = 0;
	int num = 0;
	char str[10];
	int count = 0;
	int queue[100000];
	int n = 0;


	while (1)
	{
		scanf("%d", &num);
		if (1 <= num <= 10000)
		{
			break;
		}
	}



	for (i = 0; i < num; i++)
	{
		scanf("%s", &str);

		if (strcmp(str, "push") == 0)
		{
			scanf("%d", &data);
			count++;
			enQueue(LQ, data);
			
		
		}

		else if (strcmp(str, "pop") == 0)
		{
			if (count == 0)
			{
				queue[n] = -1;
				n++;
			}
			else
			{
				count--;
				queue[n] = Front(LQ);
				deQueue(LQ);
				n++;
			}
			
			
		}

		else if (strcmp(str, "size") == 0)
		{
			queue[n] = count;
			n++;
		}

		else if (strcmp(str, "empty") == 0)
		{
			queue[n] = Empty(LQ);
			n++;
		}

		else if (strcmp(str, "front") == 0)
		{

			if (Front(LQ) == Empty(LQ))
			{
				queue[n] = -1;
				n++;
			}
			else
			{
				queue[n] = Front(LQ);
				n++;
			}
		}

		else if (strcmp(str, "back") == 0)
		{
			if (Back(LQ) == Empty(LQ))
			{
				queue[n] = -1;
				n++;
			}
			else
			{
				queue[n] = Back(LQ);
				n++;
			}
		}

	}



	for (i = 0; i < n; i++)
	{
		printf("%d\n", queue[i]);

	}




	return 0;
}
