/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:07:43 by thomkim           #+#    #+#             */
/*   Updated: 2018/04/04 14:58:08 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(char **av, t_filist list[26])
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		i;
	char	lines[26];

	fd = open(av[1], O_RDONLY);
	i = -1;
	if ((ret = read(fd, buf, BUF_SIZE)) <= 0)
		ft_err_msg("error");
	while (ret > 0 && ++i < 26)
	{
		buf[ret] = '\0';
		ft_check_board(buf);
		lines[i] = *ft_itoa(ft_no_line(buf));
		list[i].num = 'A' + i;
		ft_store(&list[i], buf);
		ret = read(fd, buf, BUF_SIZE);
	}
	lines[i + 1] = '\0';
	ft_check_line(lines);
	ft_check_connect(list);
	close(fd);
	return (i);
}

int		main(int ac, char **av)
{
	t_filist	list[26];
	int			size;
	int			pcs;
	char		**board;

	size = 0;
	ft_bzero(&list, sizeof(list));
	if (ac != 2)
		return (0);
	pcs = ft_read(av, list) + 1;
	while (size * size < 4 * pcs)
		size++;
	size += 3;
	while (1)
	{
		board = ft_create_board(size);
		ft_fill_list(list, board, 0);
		size++;
		free(board);
	}
	return (0);
}
