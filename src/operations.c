/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:29:54 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/11/30 15:34:09 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

static void	swap_operation(t_stacks *stacks, char *operation)
{
	int	temp;

	if ((operation[1] == 'a' || operation[1] == 's') && stacks->stack_a_len)
	{
		temp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = temp;
	}
	if ((operation[1] == 'b' || operation[1] == 's') && stacks->stack_b_len)
	{
		temp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = temp;
	}
}

static void	rotate_operation(t_stacks *stacks, char *operation)
{
	int	i;
	int	temp;

	if (operation[1] == 'a' || operation[1] == 'r')
	{
		i = -1;
		temp = stacks->stack_a[0];
		while (++i < stacks->stack_a_len - 1)
			stacks->stack_a[i] = stacks->stack_a[i + 1];
		stacks->stack_a[i] = temp;
	}
	if (operation[1] == 'b' || operation[1] == 'r')
	{
		i = -1;
		temp = stacks->stack_b[0];
		while (++i < stacks->stack_b_len - 1)
			stacks->stack_b[i] = stacks->stack_b[i + 1];
		stacks->stack_b[i] = temp;
	}
}

static void	reverse_rotate_operation(t_stacks *stacks, char *operation)
{
	int	i;
	int	temp;

	if (operation[2] == 'a' || operation[2] == 'r')
	{
		i = stacks->size;
		temp = stacks->stack_a[stacks->stack_a_len - 1];
		while (--i)
			stacks->stack_a[i] = stacks->stack_a[i - 1];
		stacks->stack_a[i] = temp;
	}
	if (operation[2] == 'b' || operation[2] == 'r')
	{
		i = stacks->size;
		temp = stacks->stack_b[stacks->stack_b_len - 1];
		while (--i)
			stacks->stack_b[i] = stacks->stack_b[i - 1];
		stacks->stack_b[i] = temp;
	}
}

static void	push_operation(t_stacks *stacks, char *operation)
{
	if (operation[1] == 'a')
	{
		if (stacks->stack_a_len)
			reverse_rotate_operation(stacks, "rra");
		stacks->stack_a[0] = stacks->stack_b[0];
		rotate_operation(stacks, "rb");
		stacks->stack_a_len++;
		stacks->stack_b_len--;
	}
	if (operation[1] == 'b')
	{
		if (stacks->stack_b_len)
			reverse_rotate_operation(stacks, "rrb");
		stacks->stack_b[0] = stacks->stack_a[0];
		rotate_operation(stacks, "ra");
		stacks->stack_b_len++;
		stacks->stack_a_len--;
	}
}

void	exec_operation(t_stacks *stacks, char *new_op, int print, int freeable)
{
	int			i;
	static char	curr_op[3];

	i = -1;
	if (new_op[0] == 's')
		swap_operation(stacks, new_op);
	if (new_op[0] == 'p')
		push_operation(stacks, new_op);
	if (new_op[1] == 'r' && new_op[2])
		reverse_rotate_operation(stacks, new_op);
	else if (new_op[0] == 'r')
		rotate_operation(stacks, new_op);
	if (curr_op[0] && (curr_op[0] != new_op[0] || curr_op[1] == new_op[1]
			|| (curr_op[2] != new_op[1] && curr_op[2] != new_op[2])) && print)
		ft_putstr(ft_strjoin(curr_op, "\n"), 1);
	else if (curr_op[0])
	{
		while (++i < 3)
			curr_op[i] = 0;
	}
	while (++i < 3)
		curr_op[i] = new_op[i];
	if (freeable)
		free(new_op);
}
