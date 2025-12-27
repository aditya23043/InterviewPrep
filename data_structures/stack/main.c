#include "stack.h"

int main(void)
{
	STACK stack = {0};
	stack_init(&stack);

	stack_push(&stack, 20);
	stack_push(&stack, 21);
	stack_push(&stack, 22);
	stack_push(&stack, 23);

	stack_pop(&stack);
	stack_pop(&stack);

	stack_print(stack);

	return 0;
}
