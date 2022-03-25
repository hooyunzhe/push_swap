/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyun-zhe <hyun-zhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:03:05 by hyun-zhe          #+#    #+#             */
/*   Updated: 2021/11/25 10:43:13 by hyun-zhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

static char	*get_current_line(int rv, char **str)
{
	char	*newline;
	char	*temp;
	char	*line;

	newline = ft_strchr(*str, '\n');
	line = NULL;
	if (newline)
	{
		line = ft_strtrimchr(*str, '\n');
		if (*(newline + 1))
			temp = ft_strdup(newline + 1);
		else
			temp = NULL;
		free(*str);
		*str = temp;
	}
	else if (rv == 0 && *str)
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (line);
}

static char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	int			rv;

	if (fd < 0)
		return (NULL);
	buffer = malloc((4 * sizeof(char)) + 1);
	if (!buffer)
		return (NULL);
	rv = 1;
	while (rv > 0 && !ft_strchr(str, '\n'))
	{
		rv = read(fd, buffer, 4);
		buffer[rv] = 0;
		if (rv >= 0)
			str = ft_strupdate(str, buffer);
		if (!str)
			rv = -1;
	}
	free(buffer);
	buffer = NULL;
	return (get_current_line(rv, &str));
}

static int	is_operation(t_stacks *stacks, char *str)
{
	if (!str[2])
	{
		if (!ft_strncmp(str, "sa", 2) || !ft_strncmp(str, "sb", 2)
			|| !ft_strncmp(str, "ss", 2) || !ft_strncmp(str, "ra", 2)
			|| !ft_strncmp(str, "rb", 2) || !ft_strncmp(str, "rr", 2))
		{
			return (1);
		}
		if ((!ft_strncmp(str, "pa", 2) && stacks->stack_b_len)
			|| (!ft_strncmp(str, "pb", 2) && stacks->stack_a_len))
		{
			return (1);
		}
	}
	else if (!ft_strncmp(str, "rra", 3) || !ft_strncmp(str, "rrb", 3)
		|| !ft_strncmp(str, "rrr", 3))
	{
		return (1);
	}
	return (0);
}

static int	read_execute(t_stacks *stacks)
{
	char	*line;

	line = get_next_line(0);
	while (*line > 10)
	{	
		if (is_operation(stacks, line))
			exec_operation(stacks, line, 0, 1);
		else
		{
			free(line);
			line = NULL;
			write(2, "Error\n", 6);
			return (-1);
		}
		line = get_next_line(0);
	}
	free(line);
	if (check_sorted(stacks, 'a', stacks->stack_a_len, 0))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int			result;
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	stacks = get_stacks(argc - 1, argv + 1);
	if (!stacks)
		return (-1);
	result = read_execute(stacks);
	if (result == 1)
		ft_putstr("OK\n", 0);
	else if (result == 0)
		ft_putstr("KO\n", 0);
	free(stacks->numbers);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
	return (0);
}
