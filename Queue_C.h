
#define MAX 100

struct Queue
{
	int array[MAX];
	int rear;	//Last element
	int front;	//First element
};


int IsEmpty(struct Queue *q)
{
	if (q->rear < q->front)
		return 1;
	else
		return 0;
}

void Initialize(struct Queue *q)
{
	q->front = 1;
	q->rear = 0;
}

void Insert(struct Queue *q, int data)
{
	if (q->rear < MAX - 1)
	{
		q->rear++;
		q->array[q->rear] = data;
	}
	else
		printf("Queue is full.");
	return;
}

int Remove(struct Queue *q)
{
	int data, i;
	if (IsEmpty(q) == 1)
	{
		printf("Queue is empty");
		return 0;
	}
	data = q->array[q->front];
	for (i = q->front; i < q->rear; i++)
	{
		q->array[i] = q->array[i + 1];
	}
	q->rear--;
	return data;
}
