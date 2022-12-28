/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:41:33 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 21:12:12 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/libft.h"

typedef struct s_push_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*int_array;
	int		arr_len;
	t_list	*moves;
}	t_push_swap;

int		secure_atoi(char *nbr, int *input);
int		check_duplicates(int *input, int len);
t_list	*create_list(int *input, int len);
int		*parse_params(int argc, char **argv);
void	do_nothing(void *ptr);
int		is_sorted(t_list *stack);
void	print_stacks(t_push_swap *ps);

int		swap_a(t_push_swap *ps);
int		swap_b(t_push_swap *ps);
int		swap_s(t_push_swap *ps);

int		push_a(t_push_swap *ps);
int		push_b(t_push_swap *ps);

int		rotate_a(t_push_swap *ps);
int		rotate_b(t_push_swap *ps);
int		rotate_r(t_push_swap *ps);

int		reverse_rotate_a(t_push_swap *ps);
int		reverse_rotate_b(t_push_swap *ps);
int		reverse_rotate_r(t_push_swap *ps);

#	endif