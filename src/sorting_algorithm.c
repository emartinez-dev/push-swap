/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:16:30 by franmart          #+#    #+#             */
/*   Updated: 2023/01/07 16:39:05 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* get the least number of moves to put an element on top of the Stack B and
find its place on Stack A */

void	cheapest_insertion(t_push_swap *ps)
{
	t_moves	best_moves;
	t_moves	temp_moves;
	t_list	*head;

	best_moves.total = INT_MAX;
	head = ps->b;
	while (head)
	{
		find_b_rotations(ps, head, &temp_moves);
		find_a_rotations(ps, head, &temp_moves);
		temp_moves.total = temp_moves.a_rot + temp_moves.b_rot;
		if (temp_moves.total < best_moves.total)
			swap_moves(&temp_moves, &best_moves);
		head = head->next;
	}
	rotate_n(ps, 'a', best_moves.a_rot, best_moves.a_reverse);
	rotate_n(ps, 'b', best_moves.b_rot, best_moves.b_reverse);
	push_a(ps, 0);
}

void	swap_moves(t_moves *a, t_moves *b)
{
	t_moves	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/* Calculates number of operations to put an element at the top of Stack B */
void	find_b_rotations(t_push_swap *ps, t_list *b, t_moves *moves)
{
	t_list	*head;
	int		i;
	int		size;

	head = ps->b;
	i = 0;
	size = ps->b_size;
	while (*(int *)head->content != *(int *)b->content)
	{
		head = head->next;
		i++;
	}
	if (i >= size / 2)
	{
		moves->b_rot = size - i;
		moves->b_reverse = 1;
	}
	else
	{
		moves->b_rot = i;
		moves->b_reverse = 0;
	}
}

/* Calculates the number of operations to put the first element in Stack B
into its position in Stack A*/
void	find_a_rotations(t_push_swap *ps, t_list *b, t_moves *moves)
{
	t_list	*a;
	int		i;
	int		size;

	a = ps->a;
	i = 0;
	size = ps->a_size;
	while (*(int *)b->content > *(int *)a->content)
	{
		a = a->next;
		i++;
	}
	if (*(int *)b->content < *(int *)ft_lstlast(ps->a)->content)
		i = find_position_backwards(*(int *)b->content, ps->a, ps->a_size);
	if (i >= size / 2)
	{
		moves->a_rot = size - i;
		moves->a_reverse = 1;
	}
	else
	{
		moves->a_rot = i;
		moves->a_reverse = 0;
	}
}

/* If there is a larger number at the end of the stack, we have to find it's
position backwards. In cases like 2 -> 4 7 1 3, it would be wrongly inserted at
the first position because 2 < 4, when it should be inserted between 1 and 3 */
int	find_position_backwards(int n, t_list *list, int size)
{
	int		i;
	t_list	*reverse_head;
	t_list	*reverse;

	reverse = ft_lstreverse(list);
	reverse_head = reverse;
	i = 0;
	while (n < *(int *)reverse_head->content)
	{
		reverse_head = reverse_head->next;
		i++;
	}
	ft_lstclear(&reverse, ft_do_nothing);
	return (size - i);
}
