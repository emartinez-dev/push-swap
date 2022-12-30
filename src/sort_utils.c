/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:42:11 by franmart          #+#    #+#             */
/*   Updated: 2022/12/30 17:49:07 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_max(t_list *stack)
{
	int		temp_max;
	t_list	*head;

	temp_max = INT_MIN;
	head = stack;
	while (head != NULL)
	{
		if (*(int *)head->content > temp_max)
			temp_max = *(int *)head->content;
		head = head->next;
	}
	return (temp_max);
}

int	get_min(t_list *stack)
{
	int		temp_min;
	t_list	*head;

	temp_min = INT_MAX;
	head = stack;
	while (head != NULL)
	{
		if (*(int *)head->content < temp_min)
			temp_min= *(int *)head->content;
		head = head->next;
	}
	return (temp_min);
}