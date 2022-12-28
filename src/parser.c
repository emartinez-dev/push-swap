/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:40:52 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 17:52:16 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Tengo un "problema" con el atoi este que he hecho, y es que como estoy
haciendo la comprobación a la misma vez que devuelvo, no puedo devolver un
código de error porque se entendería como un return normal del atoi, por ejemplo
devolver -1 como error no sería válido. Por esto tengo que pasarle a la función
el puntero del array donde estoy guardando los inputs, para liberarla en caso de
que el número no sea válido */

int	secure_atoi(char *atoi_nbr, int *input_arr)
{
	int		number;
	char	*str_number;

	number = ft_atoi(atoi_nbr);
	str_number = ft_itoa(number);
	if (atoi_nbr[0] == '+')
		atoi_nbr++;
	if (ft_strncmp(atoi_nbr, str_number, ft_strlen(atoi_nbr)) != 0)
	{
		ft_printf("Error: Input %s is not a valid integer.\n", atoi_nbr);
		free(input_arr);
		free(str_number);
		exit(1);
	}
	free(str_number);
	return (number);
}

int	check_duplicates(int *input_arr, int arr_len)
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
				ft_printf("Error: Input number %d is duplicated.\n",
					input_arr[i]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_list	*create_list(int *input_arr, int arr_len)
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

int	*parse_params(int argc, char **argv)
{
	int		i;
	int		param_nbr;
	int		*input_arr;

	input_arr = ft_calloc(argc - 1, sizeof(int));
	i = 1;
	while (i < argc)
	{
		param_nbr = secure_atoi(argv[i], input_arr);
		input_arr[i - 1] = param_nbr;
		i++;
	}
	if (check_duplicates(input_arr, argc - 1))
	{
		free(input_arr);
		exit(2);
	}
	return (input_arr);
}
