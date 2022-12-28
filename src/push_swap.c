/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:36:13 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 20:53:03 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	ps.int_array = parse_params(argc, argv);
	ps.arr_len = argc - 1;
	ps.stack_a = create_list(ps.int_array, ps.arr_len);
	ps.stack_b = 0;
	/*
	while (stack_a != NULL)
	{
		ft_printf("n: %d\n", *((int *)stack_a->content));
		stack_a = stack_a->next;
	}
	if (is_sorted(ps.stack_a))
		ft_printf("Está ordenado\n");
	else
		ft_printf("No está ordenado\n");
	*/
	print_stacks(&ps);
	rotate_r(&ps);
	print_stacks(&ps);
	free(ps.int_array);
	ft_lstclear(&ps.stack_a, do_nothing);
	ft_lstclear(&ps.stack_b, do_nothing);
	return (0);
}
