/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:26:23 by mizusato          #+#    #+#             */
/*   Updated: 2024/06/07 16:14:14 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef enum s_error
{
	SUCCESS = 0,
	ERROR = -42,
}			t_error;

typedef struct s_string
{
	char	*s;
	size_t	len;
	size_t	capa;
}			t_string;

typedef struct s_buf
{
	char	buf[BUFFER_SIZE];
	char	*buf_ptr;
	int		read_count;
}			t_buf;

void	*ft_memset(void *b, int c, size_t len);
void	*ft_free_str(char **str);
int		ft_alloc_str(t_string **str);
int		ft_dobble_capa(t_string **str);

char	*get_next_line(int fd);

#endif