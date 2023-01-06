/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:36:13 by franmart          #+#    #+#             */
/*   Updated: 2023/01/06 14:10:45 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stacks(t_push_swap *ps)
{
	ps->a = array_to_list(ps->int_array, ps->arr_len);
	ps->b = NULL;
	ps->a_size = ps->arr_len;
	ps->b_size = 0;
}

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;

	parse_params(argc, argv, &push_swap);
	check_duplicates(push_swap.int_array, push_swap.arr_len);
	init_stacks(&push_swap);
	sort(&push_swap);
	free(push_swap.int_array);
	ft_lstclear(&push_swap.a, ft_do_nothing);
	ft_lstclear(&push_swap.b, ft_do_nothing);
	return (0);
}
