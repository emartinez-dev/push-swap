/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:19:08 by franmart          #+#    #+#             */
/*   Updated: 2023/01/07 16:53:00 by franmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		parse_instructions(char *command, t_push_swap *ps, int command_len);
int		exec_instructions(t_push_swap *ps);

#	endif