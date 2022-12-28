/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:41:33 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 18:18:49 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/libft.h"

int		secure_atoi(char *nbr, int *input);
int		check_duplicates(int *input, int len);
t_list	*create_list(int *input, int len);
int		*parse_params(int argc, char **argv);
void	do_nothing(void *ptr);
int		is_sorted(t_list *stack);

typedef struct s_push_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*int_array;
	int		arr_len;
	t_list	*moves;
}	t_push_swap;

#	endif