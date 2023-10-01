/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:20:03 by franmart          #+#    #+#             */
/*   Updated: 2023/10/01 18:54:13 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	parse_instructions(char *command, t_push_swap *ps, int command_len)
{
	if (ft_strncmp(command, "pa\n", command_len) == 0)
		push_a(ps, 1);
	else if (ft_strncmp(command, "pb\n", command_len) == 0)
		push_b(ps, 1);
	else if (ft_strncmp(command, "sa\n", command_len) == 0)
		swap_a(ps, 1);
	else if (ft_strncmp(command, "sb\n", command_len) == 0)
		swap_b(ps, 1);
	else if (ft_strncmp(command, "ss\n", command_len) == 0)
		swap_s(ps, 1);
	else if (ft_strncmp(command, "ra\n", command_len) == 0)
		rotate_a(ps, 1);
	else if (ft_strncmp(command, "rb\n", command_len) == 0)
		rotate_b(ps, 1);
	else if (ft_strncmp(command, "rr\n", command_len) == 0)
		rotate_r(ps, 1);
	else if (ft_strncmp(command, "rra\n", command_len) == 0)
		reverse_rotate_a(ps, 1);
	else if (ft_strncmp(command, "rrb\n", command_len) == 0)
		reverse_rotate_b(ps, 1);
	else if (ft_strncmp(command, "rrr\n", command_len) == 0)
		reverse_rotate_r(ps, 1);
	else
		return (1);
	return (0);
}

int	exec_instructions(t_push_swap *ps)
{
	char	*command;
	int		status;

	if (ps->a == NULL)
		return (0);
	command = ft_gnl(STDIN_FILENO);
	status = 0;
	while (command != NULL)
	{
		if (status == 0)
			status = parse_instructions(command, ps, ft_strlen(command));
		else
			parse_instructions(command, ps, ft_strlen(command));
		free(command);
		command = ft_gnl(STDIN_FILENO);
	}
	return (status);
}
