/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:58:52 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/11/25 16:53:35 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = get_stacks(argc - 1, argv + 1);
	if (!stacks)
		return (-1);
	quick_sort(stacks, stacks->stack_a_len, "a", "b");
	exec_operation(stacks, "", 1, 0);
	free(stacks->numbers);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
	return (0);
}
