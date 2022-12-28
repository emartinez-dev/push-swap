/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:40:05 by franmart          #+#    #+#             */
/*   Updated: 2022/12/28 17:41:48 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* el por qué de esta función: los arrays de int se liberan todos de una,
entonces al utilizar lstclear, que aplica una función en cada elemento de la
lista, no tiene que hacer nada porque ya se está liberando desde fuera ese
puntero de ints
*/

void	do_nothing(void *ptr)
{
	(void) ptr;
}
