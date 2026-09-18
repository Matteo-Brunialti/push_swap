#include "push_swap.h"

float	compute_disorder(t_dll **stack)
{
	t_dll	*curr_i;
	t_dll	*curr_j;
	int		mistakes;
	int		total_pairs;

	if (!(*stack))
		return (-1);
	curr_i = (*stack);
	mistakes = 0;
	total_pairs = 0;
	while (curr_i->next != (*stack))
	{
		curr_j = curr_i->next;
		while (curr_j != (*stack))
		{
			total_pairs++;
			if (curr_i->num > curr_j->num)
				mistakes++;
			curr_j = curr_j->next;
		}
		curr_i = curr_i->next;
	}
	return ((float)mistakes / total_pairs);
}

int	my_sqrt(int num)
{
	int	i;

	if (num <= 0)
		return (0);
	i = 1;
	while (i <= (num / i))
		i++;
	if ((i * i) == num)
		return (i);
	return (i - 1);
}

void	set_rank(t_dll **stack, int len_stack)
{
	t_dll	*curr;
	t_dll	*min_node;
	int		min_value;
	int		i;

	i = 0;
	min_node = (*stack);
	while (i < len_stack)
	{
		curr = (*stack);
		min_value = INT_MAX;
		while (curr->next != (*stack))
		{
			if (curr->num < min_value && curr->rank < 0)
			{
				min_node = curr;
				min_value = min_node->num;
			}
			curr = curr->next;
		}
		if (curr->num < min_value && curr->rank < 0)
			min_node = curr;
		min_node->rank = i;
		i++;
	}
}
