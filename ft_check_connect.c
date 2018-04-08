/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_connect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:56:45 by thomkim           #+#    #+#             */
/*   Updated: 2018/04/04 14:51:58 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_connect(t_filist list[26])
{
	int	i;
	int j;
	int k;
	int count;

	i = -1;
	count = 0;
	while (++i < 26 && list[i].num != '\0')
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
			{
				if (list[i].block[j][k] == '#')
					count += ft_single_line(list, i, j, k);
			}
		}
		if (count == 6 || count == 8)
			count = 0;
		else
			ft_err_msg("error");
	}
	return (0);
}
