/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:40:52 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 17:36:44 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Tengo un "problema" con el atoi este que he hecho, y es que como estoy
haciendo la comprobación a la misma vez que devuelvo, no puedo devolver un
código de error porque se entendería como un return normal del atoi, por ejemplo
devolver -1 como error no sería válido. Por esto tengo que pasarle a la función
el puntero del array donde estoy guardando los inputs, para liberarla en caso de
que el número no sea válido */

int	secure_atoi(char *nbr, int *input)
{
	int		result;
	char	*text_result;

	result = ft_atoi(nbr);
	text_result = ft_itoa(result);
	if (nbr[0] == '+')
		nbr++;
	if (ft_strncmp(nbr, text_result, ft_strlen(nbr)) != 0)
	{
		ft_printf("Error: Input number %s is not between INT_MIN "\
		"and INT_MAX.\n", nbr);
		free(input);
		free(text_result);
		exit(1);
	}
	free(text_result);
	return (result);
}

int	check_duplicates(int *input, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (input[i] == input[j])
			{
				ft_printf("Error: Input number %d is duplicated.\n", input[i]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_list *create_list(int *input, int len)
{
	t_list	*new;
	t_list	*stack;
	int		i;

	stack = NULL;
	i = 0;
	while (i < len)
	{
		new = ft_lstnew(&input[i]);
		ft_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}

int	*parse_params(int argc, char **argv)
{
	int		i;
	int		param_value;
	int		*input;

	input = ft_calloc(argc - 1, sizeof(int));
	i = 1;
	while (i < argc)
	{
		param_value = secure_atoi(argv[i], input);
		input[i - 1] = param_value;
		i++;
	}
	if (check_duplicates(input, argc - 1))
	{
		free(input);
		exit(2);
	}
	return (input);
}

/* el por qué de esta función: los arrays de int se liberan todos de una,
entonces al utilizar lstclear, que aplica una función en cada elemento de la
lista, no tiene que hacer nada porque ya se está liberando desde fuera ese
puntero de ints
*/
void	do_nothing(void *ptr)
{
	(void) ptr;
}
