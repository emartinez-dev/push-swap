/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:31:17 by franmart          #+#    #+#             */
/*   Updated: 2023/01/05 20:39:12 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_array(int *array, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
				swap(&array[j], &array[j + 1]);
			j++;
		}
		i++;
	}
}

t_list	*reverse_linked_list(t_list *list)
{
	t_list	*new_list;
	t_list	*head;
	t_list	*head_cpy;

	new_list = NULL;
	head = list;
	while (head != NULL)
	{
		head_cpy = ft_lstnew(head->content);
		ft_lstadd_front(&new_list, head_cpy);
		head = head->next;
	}
	return (new_list);
}
