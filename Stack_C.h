#define MAX 100
struct Stack
{
	int array[MAX];
	unsigned top;
};

int isEmpty(struct Stack* stack)
{
	if (stack->top > 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
void Init(struct Stack *stack)
{
	stack->top = 0;
}

void Push(struct Stack *stack, int data)
{
	if (stack->top < MAX)
	{
		stack->array[stack->top] = data;
		stack->top++;
	}
	else
	{
		printf("Stack is full\n");
	}
}

int Pop(struct Stack *stack)
{
	if (stack->top > 0)
	{
		stack->top--;
		return stack->array[stack->top];
	}
	else
	{
		printf("Stack is empty");
		return 1;
	}
}

unsigned Stack_Size(struct Stack *stack)
{
	return stack->top;
}

void StackPrint(struct Stack *stack)
{
	if (isEmpty(stack))
		return;
	unsigned i = stack->top;
	while (i > 0)
	{
		i--;
		printf("%d ", stack->array[i]);
	}
}
