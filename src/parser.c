/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:40:52 by franmart          #+#    #+#             */
/*   Updated: 2023/03/20 11:24:56 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* this functions is unreadable because there are 3 counters, i, j and arr_i
	@arr_i:	the position of an element in the array of integers
	@i:		counter for argv
	@j:		counter for when an arg in argv includes more than 1 argument
			ex: ./push_swap 1 2 3 "9 123 54" */

void	parse_params(int argc, char **argv, t_push_swap *ps)
{
	int		i;
	int		j;
	int		arr_i;
	char	**argx;

	ps->arr_len = count_params(argc, argv);
	ps->int_array = ft_calloc(ps->arr_len, sizeof(int));
	i = 0;
	arr_i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' ') == 0)
			ps->int_array[arr_i++] = secure_atoi(argv[i], ps->int_array);
		else
		{
			j = -1;
			argx = ft_split(argv[i], ' ');
			while (argx[++j])
				ps->int_array[arr_i + j] = secure_atoi(argx[j], ps->int_array);
			arr_i += j;
			ft_free_array(argx);
		}
	}
}

/* atoi that checks if the original number was truncated in the conversion.
(If the number was truncated the execution is stopped and the program exits.
Because I can't return any special value like -1 on error, I must free the array
inside this function if an error ocurs) */

int	secure_atoi(char *atoi_nbr, int *input_arr)
{
	long	number;

	number = ft_atol(atoi_nbr);
	if (number != (int) number)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		free(input_arr);
		exit(1);
	}
	return (number);
}

void	check_duplicates(int *input_arr, int arr_len)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_len)
	{
		j = i + 1;
		while (j < arr_len)
		{
			if (input_arr[i] == input_arr[j])
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				free(input_arr);
				exit(2);
			}
			j++;
		}
		i++;
	}
}

t_list	*array_to_list(int *input_arr, int arr_len)
{
	t_list	*new;
	t_list	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (i < arr_len)
	{
		new = ft_lstnew(&input_arr[i]);
		ft_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}

int	count_params(int argc, char **argv)
{
	int	i;
	int	count;
	int	total;

	i = 1;
	total = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ') != 0)
		{
			count = ft_count_words(argv[i], ' ') - 1;
			total += count - 1;
		}
		i++;
	}
	total += i - 1;
	return (total);
}
