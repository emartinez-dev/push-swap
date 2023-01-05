/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:16:30 by franmart          #+#    #+#             */
/*   Updated: 2023/01/05 12:22:22 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_moves(t_move_finder *a, t_move_finder *b)
{
	t_move_finder temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/* check the position of the element we want to move out of stack b*/
void	find_moves_b(t_push_swap *ps, t_list *b, t_move_finder *moves)
{
	t_list	*temp_b;
	int		i;
	int		size;

	temp_b = ps->b;
	i = 0;
	size = ft_lstsize(ps->b);
	while (*(int *)temp_b->content != *(int *)b->content)
	{
		temp_b = temp_b->next;
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

/* find the position to insert it on stack a*/
void	find_moves_a(t_push_swap *ps, t_list *b, t_move_finder *moves)
{
	int		b_value;
	t_list	*a;
	int		i;
	int		size;

	a = ps->a;
	b_value = *(int *)b->content;
	i = 0;
	size = ft_lstsize(ps->a);
	while (b_value > *(int *)a->content)
	{
		a = a->next;
		i++;
	}
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

/* get the least number of moves to put an element on top of the Stack B and
find its place on Stack A */

void	do_best_moves(t_push_swap *ps)
{
	t_move_finder	moves;
	t_move_finder	temp_moves;
	t_list			*temp_b;

	moves.total = INT_MAX;
	temp_b = ps->b;
	while (temp_b)
	{
		find_moves_b(ps, temp_b, &temp_moves);
		find_moves_a(ps, temp_b, &temp_moves);
		temp_moves.total = temp_moves.a_rot + temp_moves.b_rot;
		if (temp_moves.total < moves.total)
			swap_moves(&temp_moves, &moves);
		temp_b = temp_b->next;
	}
	rotate_n(ps, 'a', moves.a_rot, moves.a_reverse);
	rotate_n(ps, 'b', moves.b_rot, moves.b_reverse);
	push_a(ps);
}