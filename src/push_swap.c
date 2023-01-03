/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:36:13 by franmart          #+#    #+#             */
/*   Updated: 2023/01/03 13:34:24 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	t_list		*stack_a;

	(void) stack_a;
	ps.arr_len = count_params(argc, argv);
	parse_params(argc, argv, &ps);
	ps.a = create_list(ps.int_array, ps.arr_len);
	ps.b = 0;
	sort(&ps);
	//print_stacks(&ps);
	free(ps.int_array);
	ft_lstclear(&ps.a, do_nothing);
	ft_lstclear(&ps.b, do_nothing);
	return (0);
}
