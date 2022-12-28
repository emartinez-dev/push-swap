/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:36:13 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 17:38:07 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*head_node;
	int		*int_array;

	int_array = parse_params(argc, argv);
	stack = create_list(int_array, argc - 1);
	head_node = stack;
	while (stack != NULL)
	{
		ft_printf("n: %d\n", *((int *)stack->content));
		stack = stack->next;
	}
	ft_printf("Head node: %d\n", *((int *)head_node->content));
	free(int_array);
	ft_lstclear(&stack, do_nothing);
	return (0);
}
