/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:20:24 by franmart          #+#    #+#             */
/*   Updated: 2023/01/07 16:59:21 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

int	main(int argc, char **argv)
{
	t_push_swap	push_swap;
	int			status_code;

	parse_params(argc, argv, &push_swap);
	check_duplicates(push_swap.int_array, push_swap.arr_len);
	init_stacks(&push_swap);
	status_code = exec_instructions(&push_swap);
	if (status_code == 1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else
	{
		if (is_sorted(push_swap.a) && push_swap.b == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free(push_swap.int_array);
	ft_lstclear(&push_swap.a, ft_do_nothing);
	ft_lstclear(&push_swap.b, ft_do_nothing);
	return (0);
}
