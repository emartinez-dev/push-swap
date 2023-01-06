/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:36:13 by franmart          #+#    #+#             */
/*   Updated: 2023/01/06 12:39:02 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;

	push_swap.arr_len = count_params(argc, argv);
	parse_params(argc, argv, &push_swap);
	push_swap.a = create_list(push_swap.int_array, push_swap.arr_len);
	push_swap.b = NULL;
	push_swap.a_size = push_swap.arr_len;
	push_swap.b_size = 0;
	sort(&push_swap);
	free(push_swap.int_array);
	ft_lstclear(&push_swap.a, ft_do_nothing);
	ft_lstclear(&push_swap.b, ft_do_nothing);
	return (0);
}
