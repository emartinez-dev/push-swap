/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:41:33 by franmart          #+#    #+#             */
/*   Updated: 2023/01/06 12:45:59 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/libft.h"

typedef struct s_push_swap
{
	t_list	*a;
	t_list	*b;
	int		a_size;
	int		b_size;
	int		*int_array;
	int		arr_len;
	int		min;
	int		max;
	int		median;
	t_list	*moves;
}	t_push_swap;

typedef struct s_move_finder
{
	int	a_rot;
	int	a_reverse;
	int	b_rot;
	int	b_reverse;
	int	total;
}	t_move_finder;

int		secure_atoi(char *nbr, int *input);
void	check_duplicates(int *input_arr, int arr_len);
t_list	*create_list(int *input, int len);
void	parse_params(int argc, char **argv, t_push_swap *ps);

/* utils.c */
int		is_sorted(t_list *stack);
void	print_stacks(t_push_swap *ps);
int		count_params(int argc, char **argv);

/* operations */
void	swap_a(t_push_swap *ps, int mute);
void	swap_b(t_push_swap *ps, int mute);
void	swap_s(t_push_swap *ps);
void	push_a(t_push_swap *ps);
void	push_b(t_push_swap *ps);
void	push_n(t_push_swap *ps, char stack, int n);
void	rotate_a(t_push_swap *ps, int mute);
void	rotate_b(t_push_swap *ps, int mute);
void	rotate_r(t_push_swap *ps);
void	rotate_n(t_push_swap *ps, char stack, int n, int reverse);
void	reverse_rotate_a(t_push_swap *ps, int mute);
void	reverse_rotate_b(t_push_swap *ps, int mute);
void	reverse_rotate_r(t_push_swap *ps);

/* sort.c */
void	sort(t_push_swap *ps);
void	sort_best_insertion(t_push_swap *ps);
void	align_stack(t_push_swap *ps);

/* move_finder.c */
void	do_best_moves(t_push_swap *ps);

/* sort_utils.c */
int		get_max(t_list *stack);
int		get_min(t_list *stack);
int		get_median(t_list *stack);
void	optimum_rotate(t_push_swap *ps, char stack_label, int min, int max);

#	endif