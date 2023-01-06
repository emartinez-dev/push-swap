/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:40:52 by franmart          #+#    #+#             */
/*   Updated: 2023/01/06 12:36:07 by franmart         ###   ########.fr       */
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
				ft_printf("Error: Input number %d is duplicated.\n",
					input_arr[i]);
				free(input_arr);
				exit(2);
			}
			j++;
		}
		i++;
	}
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

/* esta función es bastante compleja porque hay 3 contadores, i, j y arr_i 
arr_i controla en qué posición del array de enteros se pone cada número
i controla el bucle de los argumentos
j controla el bucle de los argumentos compuestos, los que pasen más de un param
*/
void	parse_params(int argc, char **argv, t_push_swap *ps)
{
	int		i;
	int		j;
	int		arr_i;
	char	**s_arg;

	ps->int_array = ft_calloc(ps->arr_len, sizeof(int));
	i = 1;
	arr_i = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ') == 0)
			ps->int_array[arr_i] = secure_atoi(argv[i], ps->int_array);
		else
		{
			j = -1;
			s_arg = ft_split(argv[i], ' ');
			while (s_arg[++j])
				ps->int_array[arr_i + j] = secure_atoi(s_arg[j], ps->int_array);
			arr_i++;
			ft_free_array(s_arg);
		}
		arr_i++;
		i++;
	}
	check_duplicates(ps->int_array, ps->arr_len);
}
