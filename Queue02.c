#include<stdio.h>

int N = 0;
int M = 0;
int V = 0;
int queue[1000] = {0, };
int mat[1000][1000] = {0,};
int check[1000] = {0,};
int n = 0;
int head = 0;
int rear = 0;


int Empty()
{
	return (head == rear);

}

void enqueue(int n)
{
	queue[head++] = n;
	head = head % 1000;
}

int dequeue()
{
	int data;
	if (Empty())
		return -1;
	else
	{
		data = queue[rear++];
		rear = rear % 1000;
		return data;

	}

}



void dfs(int v)
{
	printf("%d ", v);

	check[v] = 1;            
	for (int i = 1; i <= N; i++) {
		if (check[i] == 1 || mat[v][i] == 0)
			continue;
		dfs(i);                
	}

}

void bfs(int v)
{
	int i = 0;
	int data = 0;
	enqueue(v);
	check[v] = true;

	while (!Empty())
	{
		data = dequeue();
		printf("%d ", data);
		for (i = 1; i <= N; i++)
		{
			if (mat[data][i] && !check[i])
			{
				enqueue(i);
				check[i] = true;
			}

		}

	}

}

int main() {
	int x = 0; 
	int y = 0;
	int i = 0;
	
	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &V);
		
	for (int i = 0; i<M; i++) 
	{  
		scanf("%d", &x);
		scanf("%d", &y);
		mat[x][y] = mat[y][x] = 1;   
	}


	dfs(V);

	printf("\n");
	
	for (i = 1; i<=N; i++)
	{
		check[i] = 0;
	}

	bfs(V);
	printf("\n");

	return 0;
}
