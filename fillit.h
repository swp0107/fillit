/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:16:18 by thomkim           #+#    #+#             */
/*   Updated: 2018/04/04 14:43:15 by thomkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include <string.h>
# include <strings.h>
# include <stdio.h>

# define BUF_SIZE 21

typedef struct	s_filist
{
	char		num;
	char		block[4][5];
	int			i;
	int			j;
}				t_filist;

/*
** validity of the board
*/
void			ft_check_board(char *str);
int				ft_single_line(t_filist list[26], int i, int j, int k);
int				ft_check_connect(t_filist list[26]);
int				ft_no_line(char *str);
void			ft_check_line(char *str);

/*
** ft_tetriminos
*/
void			ft_store(t_filist *list, char buf[BUF_SIZE + 1]);
void			ft_i_position(t_filist *list);
void			ft_j_position(t_filist *list);

/*
** error
*/
void			ft_err_msg(char *str);

/*
** ft_board
*/
char			**ft_create_board(int size);
void			ft_bigger_board(char **board, int size);
void			ft_print_board(char **board);

/*
** ft_fillit
*/
int				ft_fill_check(t_filist list, char **board, int bi, int bj);
void			ft_fill_list(t_filist list[26], char **board, int n);
void			ft_fill_it(t_filist list, char **board, int bi, int bj);
void			ft_delete_it(t_filist list, char **board, int n);

#endif
