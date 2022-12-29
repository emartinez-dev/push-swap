/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:40:05 by franmart          #+#    #+#             */
/*   Updated: 2022/12/29 14:43:48 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* el por qué de esta función: los arrays de int se liberan todos de una,
entonces al utilizar lstclear, que aplica una función en cada elemento de la
lista, no tiene que hacer nada porque ya se está liberando desde fuera ese
puntero de ints
*/

void	do_nothing(void *ptr)
{
	(void) ptr;
}

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	print_stacks(t_push_swap *ps)
{
	t_list	*stack_a;
	t_list	*stack_b;

	ft_printf("Stack A\n");
	stack_a = ps->stack_a;
	stack_b = ps->stack_b;
	while (stack_a != NULL)
	{
		ft_printf("%d\t", *(int *)stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\nStack B\n");
	while (stack_b != NULL)
	{
		ft_printf("%d\t", *(int *)stack_b->content);
		stack_b = stack_b->next;
	}
	ft_printf("\n\n");
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
