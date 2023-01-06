/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:01:57 by franmart          #+#    #+#             */
/*   Updated: 2023/01/06 14:16:51 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	get_stats(t_push_swap *ps)
{
	ps->max = get_max(ps->a);
	ps->min = get_min(ps->a);
	ps->median = get_median(ps->a);
}

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
			temp_min = *(int *)head->content;
		head = head->next;
	}
	return (temp_min);
}

int	get_median(t_list *stack)
{
	int		*array;
	int		size;
	int		i;
	t_list	*head;
	int		median;

	i = -1;
	size = ft_lstsize(stack);
	array = ft_calloc(size, sizeof(int));
	head = stack;
	while (++i < size)
	{
		array[i] = *(int *)head->content;
		head = head->next;
	}
	ft_bubblesort(array, size);
	if (size % 2 != 0)
		median = array[size / 2];
	else
		median = (array[size / 2 - 1] + array[size / 2]) / 2;
	free(array);
	return (median);
}

int	get_min_or_max(t_list *stack, int min, int max)
{
	t_list	*head;
	int		minmax;
	int		i;

	i = 0;
	minmax = -1;
	head = stack;
	while (head != NULL && minmax == -1)
	{
		if (*(int *)head->content == min || *(int *)head->content == max)
			minmax = i;
		head = head->next;
		i++;
	}
	return (minmax);
}
