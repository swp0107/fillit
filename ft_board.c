/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:01:24 by thomkim           #+#    #+#             */
/*   Updated: 2018/04/04 14:58:35 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_board(char **board)
{
	int i;
	int j;

	i = 0;
	while (board[i][0] != '+')
	{
		j = 0;
		while (board[i][j] != '+')
		{
			write(1, &board[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	exit(0);
}

void	ft_bigger_board(char **board, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j > size - 4 || i > size - 4)
				board[i][j++] = '+';
			else
				board[i][j++] = '.';
		}
	}
}

char	**ft_create_board(int size)
{
	int		i;
	char	**board;

	i = 0;
	board = (char**)malloc(sizeof(char*) * (size + 1));
	if (board == NULL)
		return (NULL);
	board[size] = NULL;
	while (i < size)
	{
		board[i] = (char*)malloc(sizeof(char) * (size + 1));
		if (board[i] == NULL)
			return (NULL);
		board[i][size] = '\0';
		i++;
	}
	ft_bigger_board(board, size);
	return (board);
}
