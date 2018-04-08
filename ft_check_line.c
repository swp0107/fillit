/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:48:36 by thomkim           #+#    #+#             */
/*   Updated: 2018/04/04 14:48:34 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_line(char *str)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (str[i])
	{
		if (i == (len - 1) && str[i] != '4')
			ft_err_msg("error");
		if (i < (len - 1) && str[i] != '5')
			ft_err_msg("error");
		i++;
	}
}
