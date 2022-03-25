#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stacks
{
	int	*numbers;
	int	*stack_a;
	int	*stack_b;
	int	size;
	int	stack_a_len;
	int	stack_b_len;
}		t_stacks;

void		quick_sort(t_stacks *stacks, int len, char *start, char *dest);
char		*sort_small(t_stacks *stacks, int len_a, int len_b, int diff);
int			compare_num(t_stacks *stacks, int indexA, int indexB, int rev);
int			check_sorted(t_stacks *stacks, char stack, int len, int desc);
t_stacks	*get_stacks(int size, char **args);
void		exec_operation(t_stacks *stacks, char *operation, int print, int freeable);

#endif
