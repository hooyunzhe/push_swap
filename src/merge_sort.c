/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:46:53 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/11/18 10:49:45 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/push_swap.h"
#include "../libft/libft.h"

// void	print_stacks(t_stacks *stacks)
// {
// 	printf("stack_a len: %d\n", stacks->stack_a_len);
// 	printf("numbers[stack_a[i]]: ");
// 	int i = -1;
// 	while (++i < stacks->stack_a_len)
// 		printf("%d ", stacks->numbers[stacks->stack_a[i]]);
// 	printf("\n");
// 	printf("stack_b len: %d\n", stacks->stack_b_len);
// 	printf("numbers[stack_b[i]]: ");
// 	i = -1;
// 	while (++i < stacks->stack_b_len)
// 		printf("%d ", stacks->numbers[stacks->stack_b[i]]);
// 	printf("\n");
// }

// void	merge_sort_merge(t_stacks *stacks, int sizeA, int sizeB, char *dest)
// {
// 	int	i;
// 	int	j;

// 	while (sizeA > 0 || sizeB > 0)
// 	{
// 		if (*dest == 'a')
// 		{
// 			i = stacks->stack_a[stacks->stack_a_len - 1];
// 			j = stacks->stack_b[0];
// 			if ((compare_num(stacks, i, j, 0) || !sizeB) && sizeA-- > 0)
// 				exec_operation(stacks, ft_strjoin("rr", dest));
// 			else if (sizeB-- > 0)
// 				exec_operation(stacks, ft_strjoin("p", dest));
// 		}
// 		else if (*dest == 'b')
// 		{
// 			i = stacks->stack_b[stacks->stack_b_len - 1];
// 			j = stacks->stack_a[0];
// 			if ((compare_num(stacks, i, j, 1) || !sizeA) && sizeB-- > 0)
// 				exec_operation(stacks, ft_strjoin("rr", dest));
// 			else if (sizeA-- > 0)
// 				exec_operation(stacks, ft_strjoin("p", dest));
// 		}
// 	}
// }

// void	merge_sort_three(t_stacks *stacks)
// {
// 	int	index1;
// 	int	index2;
// 	int	index3;

// 	while (!check_sorted(stacks, 'a', stacks->stack_a_len, 0))
// 	{
// 		index1 = stacks->stack_a[0];
// 		index2 = stacks->stack_a[1];
// 		index3 = stacks->stack_a[2];
// 		if (stacks->numbers[index1] > stacks->numbers[index2])
// 			exec_operation(stacks, "sa");
// 		else if (stacks->numbers[index2] > stacks->numbers[index3])
// 			exec_operation(stacks, "rra");
// 	}
// }	

// void	merge_sort(t_stacks *stacks, int size, char *dest)
// {
// 	int	i;

// 	if (size == 3 && *dest == 'a' && stacks->stack_a_len == 3)
// 		merge_sort_three(stacks);
// 	else if (size == 2)
// 	{
// 		i = size;
// 		if (compare_num(stacks, stacks->stack_a[0], stacks->stack_a[1], 0))
// 			exec_operation(stacks, "sa");
// 		while (*dest == 'b' && i--)
// 			exec_operation(stacks, "pb");
// 	}
// 	else if (size > 2)
// 	{
// 		merge_sort(stacks, (size / 2) + (size % 2 == 1), "b");
// 		merge_sort(stacks, size / 2, "a");
// 		i = (size / 2) + (size % 2 == 1) * (*dest == 'b');
// 		while (((*dest == 'a' && stacks->stack_a_len > size)
// 				|| (*dest == 'b' && stacks->stack_b_len > size)) && i--)
// 			exec_operation(stacks, ft_strjoin("r", dest));
// 		merge_sort_merge(stacks, size / 2, (size / 2) + (size % 2 == 1), dest);
// 	}
// }
