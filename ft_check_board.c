/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:59:28 by thomkim           #+#    #+#             */
/*   Updated: 2018/04/04 14:46:10 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_board(char *str)
{
	int	n_dot;
	int n_hash;
	int i;

	n_dot = 0;
	n_hash = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			ft_err_msg("error");
		if (str[i] == '.')
			n_dot++;
		if (str[i] == '#')
			n_hash++;
		i++;
	}
	if (n_dot != 12 || n_hash != 4)
		ft_err_msg("error");
}
