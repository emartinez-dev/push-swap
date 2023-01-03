/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:41:33 by franmart          #+#    #+#             */
/*   Updated: 2023/01/03 11:11:05 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/libft.h"

typedef struct s_push_swap
{
	t_list	*a;
	t_list	*b;
	int		*int_array;
	int		arr_len;
	t_list	*moves;
}	t_push_swap;

int		secure_atoi(char *nbr, int *input);
void	check_duplicates(int *input_arr, int arr_len);
t_list	*create_list(int *input, int len);
void	parse_params(int argc, char **argv, t_push_swap *ps);

/* utils.c */
void	do_nothing(void *ptr);
int		is_sorted(t_list *stack);
void	print_stacks(t_push_swap *ps);
void	free_array(char **arr);
int		count_params(int argc, char **argv);

/* operations */
int		swap_a(t_push_swap *ps, int mute);
int		swap_b(t_push_swap *ps, int mute);
int		swap_s(t_push_swap *ps);
int		push_a(t_push_swap *ps);
int		push_b(t_push_swap *ps);
void	push_n(t_push_swap *ps, char stack, int n);
int		rotate_a(t_push_swap *ps, int mute);
int		rotate_b(t_push_swap *ps, int mute);
int		rotate_r(t_push_swap *ps);
void	rotate_n(t_push_swap *ps, char stack, int n, int reverse);
int		reverse_rotate_a(t_push_swap *ps, int mute);
int		reverse_rotate_b(t_push_swap *ps, int mute);
int		reverse_rotate_r(t_push_swap *ps);

/* sort.c */
void	sort(t_push_swap *ps);

/* sort_utils.c */
int		get_max(t_list *stack);
int		get_min(t_list *stack);
void	optimum_rotate(t_push_swap *ps, char stack_label, int min, int max);

#	endif