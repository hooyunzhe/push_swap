/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:23:16 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/11/25 13:50:43 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

char	*sort_small(t_stacks *stacks, int len_a, int len_b, int diff)
{
	if (compare_num(stacks, stacks->stack_a[0], stacks->stack_a[1], 0)
		&& compare_num(stacks, stacks->stack_b[0], stacks->stack_b[1], 1)
		&& len_a > 1 && len_b > 1)
		return ("ss");
	else if (compare_num(stacks, stacks->stack_a[0], stacks->stack_a[1], 0)
		&& len_a > 1)
		return ("sa");
	else if (compare_num(stacks, stacks->stack_b[0], stacks->stack_b[1], 1)
		&& len_b > 1)
		return ("sb");
	else if (diff == 3 || (len_a == 3 && !check_sorted(stacks, 'a', len_a, 0)
			&& len_b == 3 && !check_sorted(stacks, 'b', len_b, 1)))
		return ("rr");
	else if (diff == 2 || (len_a == 3 && !check_sorted(stacks, 'a', len_a, 0)))
		return ("ra");
	else
		return ("rb");
}

int	compare_num(t_stacks *stacks, int indexA, int indexB, int rev)
{
	if (rev)
	{
		if (stacks->numbers[indexA] < stacks->numbers[indexB])
			return (1);
	}
	else
	{
		if (stacks->numbers[indexA] > stacks->numbers[indexB])
			return (1);
	}
	return (0);
}

int	check_sorted(t_stacks *stacks, char stack, int len, int desc)
{
	int	i;
	int	*c_stack;

	i = -1;
	if (stack == 'a')
		c_stack = stacks->stack_a;
	else
		c_stack = stacks->stack_b;
	while (++i < len - 1)
	{
		if (!desc
			&& stacks->numbers[c_stack[i]] > stacks->numbers[c_stack[i + 1]])
			return (0);
		if (desc
			&& stacks->numbers[c_stack[i]] < stacks->numbers[c_stack[i + 1]])
			return (0);
	}
	return (1);
}

static int	*get_nums(int size, char **args, int freeable)
{
	int	i;
	int	j;
	int	*stack;

	i = size;
	stack = malloc(size * sizeof(int));
	while (--i >= 0)
	{
		j = size;
		while (--j > i || j == size - 1)
		{
			if (!ft_isnum(args[i]) || ft_atoi(args[i]) == stack[j]
				|| ft_atol(args[i]) > INT_MAX || ft_atol(args[i]) < INT_MIN)
			{
				free(stack);
				write(2, "Error\n", 6);
				return (NULL);
			}
		}
		stack[i] = ft_atoi(args[i]);
		if (freeable)
			free(args[i]);
	}
	return (stack);
}

t_stacks	*get_stacks(int size, char **args)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (size == 1)
		args = ft_split(args[0], ' ');
	stacks->size = ft_strslen(args);
	stacks->numbers = get_nums(ft_strslen(args), args, size == 1);
	if (size == 1)
		free(args);
	if (!stacks->numbers)
	{
		free(stacks);
		return (NULL);
	}
	stacks->stack_a = malloc(stacks->size * sizeof(int));
	stacks->stack_b = malloc(stacks->size * sizeof(int));
	size = stacks->size;
	while (--size >= 0)
	{
		stacks->stack_a[size] = size;
		stacks->stack_b[size] = 0;
	}
	stacks->stack_a_len = stacks->size;
	stacks->stack_b_len = 0;
	return (stacks);
}
