/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:40:52 by franmart          #+#    #+#             */
/*   Updated: 2022/12/27 14:00:55 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	secure_atoi(char *nbr)
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
		free(text_result);
		exit(1);
	}
	free(text_result);
	return (result);
}

int	parse_params(int argc, char **argv)
{
	int		i;
	int		result;

	i = 1;
	while (i < argc)
	{
		result = secure_atoi(argv[i]);
		ft_printf("%d\n", result);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	status;
	status = parse_params(argc, argv);
	ft_printf("Status: %d\n", status);
	return (0);
}