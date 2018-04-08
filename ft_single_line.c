/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:54:42 by thomkim           #+#    #+#             */
/*   Updated: 2018/03/20 08:20:50 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_single_line(t_filist list[26], int i, int j, int k)
{
	int count;

	count = 0;
	if (j > 0 && list[i].block[j - 1][k] == '#')
		count++;
	if (j < 3 && list[i].block[j + 1][k] == '#')
		count++;
	if (k > 0 && list[i].block[j][k - 1] == '#')
		count++;
	if (k < 3 && list[i].block[j][k + 1] == '#')
		count++;
	return (count);
}
