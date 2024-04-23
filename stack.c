#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct Stack {
	Node *head;
} Stack;

Node *pop(Stack *stack);
Node *peek(Stack *stack);
void push(Stack *stack, int value);
void deleteStack(Stack *stack);
int isEmpty(Stack *stack);

int main() {
	printf("hello stack\n");

	Stack *s = malloc(sizeof(Stack));
	s->head = NULL;

	printf("%d\n", isEmpty(s));

	push(s, 5);
	push(s, 10);
	push(s, 15);

	Node *popped = pop(s);
	

	if (popped != NULL) {
		printf("popped: %d\n", popped->value);
		free(popped);
	} else {
		printf("no\n");
	}

	Node *peeked = peek(s);

	if (peeked != NULL) {
		printf("top of stack: %d\n", peeked->value);
	} else {
		printf("Stack is empty!\n");
	}

	return 1;
}

Node *pop(Stack *stack) {

	if (stack->head == NULL) {
		printf("Stack is empty!\n");
		return NULL;
	}
			

	Node *popped = stack->head;
	stack->head = popped->next;
	popped->next = NULL;

	return popped;
}

Node *peek(Stack *stack) {

	if (stack->head == NULL) {
		printf("Stack is empty!\n");
		return NULL;
	}

	Node *peeked = stack->head;

	return peeked;
}

int isEmpty(Stack *stack) {
	if (stack->head == NULL) {
		return true;
	} else {
		return false;
	}
}

void push(Stack *stack, int value) {

	Node *newNode = malloc(sizeof(Node));

	newNode->value = value;
	
	newNode->next = stack->head;
	stack->head = newNode;

}

void deleteStack(Stack *stack) {
	Node current = stack->head;

	while (current != null) {
		Node *temp = current; // current is a ptr so we create a new node ptr and set it to current
		current = current->next; // set current to next
		free(temp) // we can now free temp
	}

	free(stack);
}

