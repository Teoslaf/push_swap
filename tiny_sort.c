#include "push_swap.c"

int get_max_index(t_stack *stack)
{
	int max_value = stack->value; 
	int max_index = stack->index;

	while (stack != NULL)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_index = stack->index;
		}

		stack = stack->next;
	}

	return max_index;
}
