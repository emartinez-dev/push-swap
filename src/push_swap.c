/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:36:13 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 17:43:58 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*head_node;
	int		*int_array;

	(void) stack_b;
	int_array = parse_params(argc, argv);
	stack_a = create_list(int_array, argc - 1);
	head_node = stack_a;
	while (stack_a != NULL)
	{
		ft_printf("n: %d\n", *((int *)stack_a->content));
		stack_a = stack_a->next;
	}
	ft_printf("Head node: %d\n", *((int *)head_node->content));
	free(int_array);
	ft_lstclear(&stack_a, do_nothing);
	return (0);
}
