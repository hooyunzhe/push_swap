/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:04:10 by hyun-zhe          #+#    #+#             */
/*   Updated: 2022/01/25 13:56:52 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

static int	comp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

static int	get_median(t_stacks *stacks, int len, char dest)
{
	int	i;
	int	*nums;

	i = -1;
	if (dest == 'a')
	{
		nums = malloc(stacks->stack_a_len * sizeof(int));
		while (++i < stacks->stack_a_len)
			nums[i] = stacks->numbers[stacks->stack_a[i]];
		qsort(nums, stacks->stack_a_len, sizeof(int), comp);
	}
	else
	{
		nums = malloc(stacks->stack_b_len * sizeof(int));
		while (++i < stacks->stack_b_len)
			nums[i] = stacks->numbers[stacks->stack_b[i]];
		qsort(nums, stacks->stack_b_len, sizeof(int), comp);
	}
	if (dest == 'a')
		i = nums[len / 2];
	else
		i = nums[stacks->stack_b_len - len / 2 - len % 2];
	free(nums);
	return (i);
}

static void	quick_sort_small(t_stacks *stacks, int len_a, int len_b)
{
	int		rotated_a;
	int		rotated_b;
	char	*op;

	rotated_a = stacks->stack_a_len == 3 && stacks->stack_b_len <= 3;
	rotated_b = stacks->stack_b_len == 3 && stacks->stack_a_len <= 3;
	while (!check_sorted(stacks, 'a', len_a, 0)
		|| !check_sorted(stacks, 'b', len_b, 1)
		|| (rotated_a && stacks->stack_a_len != 3)
		|| (rotated_b && stacks->stack_b_len != 3))
	{
		op = sort_small(stacks, len_a, len_b, 2 * rotated_a + rotated_b);
		if (op[0] == 'r' && (rotated_a || rotated_b))
			exec_operation(stacks, ft_strjoin("r", op), 1, 1);
		else
			exec_operation(stacks, op, 1, 0);
		if (rotated_a && op[0] == 'r' && (op[1] == 'a' || op[1] == 'r'))
			rotated_a--;
		else if (op[0] == 'r' && (op[1] == 'a' || op[1] == 'r'))
			rotated_a++;
		if (rotated_b && op[0] == 'r' && (op[1] == 'b' || op[1] == 'r'))
			rotated_b--;
		else if (op[0] == 'r' && (op[1] == 'b' || op[1] == 'r'))
			rotated_b++;
	}
}

static void	quick_sort_split(t_stacks *stacks, int len, char *start, char *dest)
{
	int	i;
	int	rotated;
	int	median;

	i = 0;
	rotated = 0;
	median = get_median(stacks, len, start[0]);
	while (i < len / 2 + ((len % 2) * dest[0] == 'a'))
	{
		if (*dest == 'b' && stacks->numbers[stacks->stack_a[0]] < median
			&& i++ >= 0)
			exec_operation(stacks, "pb", 1, 0);
		else if (*dest == 'a' && stacks->numbers[stacks->stack_b[0]] >= median
			&& i++ >= 0)
			exec_operation(stacks, "pa", 1, 0);
		else if (rotated++ >= 0)
			exec_operation(stacks, ft_strjoin("r", start), 1, 1);
	}
	while (((dest[0] == 'b' && stacks->stack_a_len != len / 2 + len % 2)
			|| (dest[0] == 'a' && stacks->stack_b_len != len / 2)) && rotated--)
		exec_operation(stacks, ft_strjoin("rr", start), 1, 1);
}

void	quick_sort(t_stacks *stacks, int len, char *start, char *dest)
{
	int	i;

	i = 0;
	if (len <= 3)
		quick_sort_small(stacks, len * (*start == 'a'), len * (*start == 'b'));
	else if (!check_sorted(stacks, *start, len, *start == 'b')
		|| len != stacks->size)
	{
		quick_sort_split(stacks, len, start, dest);
		if (len <= 6)
			quick_sort_small(stacks, len / 2 + len % 2, len / 2);
		else
		{
			quick_sort(stacks, len / 2 + len % 2, "a", "b");
			if (len / 2 > 3)
				quick_sort(stacks, len / 2, "b", "a");
			else
				quick_sort_small(stacks, 0, len / 2);
		}
		while (len <= 7 && i++ < len / 2)
			exec_operation(stacks, "pa", 1, 0);
	}
}
