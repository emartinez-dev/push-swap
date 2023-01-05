/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:42:11 by franmart          #+#    #+#             */
/*   Updated: 2023/01/05 12:12:49 by franmart         ###   ########.fr       */
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
			temp_min = *(int *)head->content;
		head = head->next;
	}
	return (temp_min);
}

int	get_mid_point(t_list *stack, int min, int max)
{
	t_list	*head;
	int		mid_point;
	int		i;

	i = 0;
	mid_point = -1;
	head = stack;
	while (head != NULL && mid_point == -1)
	{
		if (*(int *)head->content == min || *(int *)head->content == max)
			mid_point = i;
		head = head->next;
		i++;
	}
	return (mid_point);
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
	sort_array(array, size);
	if (size % 2 != 0)
		median = array[size / 2];
	else
		median = (array[size / 2 - 1] + array[size / 2]) / 2;
	free(array);
	return (median);
}

/*
this functions calculates the minimum amount of moves to push min or max
value to the other stack.
*/
void	optimum_rotate(t_push_swap *ps, char stack_label, int min, int max)
{
	int		mid_point;
	t_list	*stack;
	int		size;

	if (stack_label == 'a')
		stack = ps->a;
	if (stack_label == 'b')
		stack = ps->b;
	size = ft_lstsize(stack);
	mid_point = get_mid_point(stack, min, max);
	if (mid_point >= size / 2)
		rotate_n(ps, stack_label, size - mid_point, 1);
	else
		rotate_n(ps, stack_label, mid_point, 0);
	if (stack_label == 'a')
		push_b(ps);
	if (stack_label == 'b')
		push_a(ps);
}
