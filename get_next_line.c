/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:25:17 by mizusato          #+#    #+#             */
/*   Updated: 2024/06/07 16:13:57 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_get_char(t_buf **buf, int fd)
{
	if ((*buf)->read_count == 0)
	{
		(*buf)->read_count = read(fd, (*buf)->buf, BUFFER_SIZE);
		if ((*buf)->read_count < 0)
			return (ERROR);
		(*buf)->buf_ptr = (*buf)->buf;
	}
	(*buf)->read_count--;
	if ((*buf)->read_count >= 0)
		return ((unsigned char)*((*buf)->buf_ptr++));
	return (EOF);
}

static int	ft_add_char(t_string **str, char c)
{
	int		result;

	if (!((*str)->s))
	{
		result = ft_alloc_str(str);
		if (result == ERROR)
			return (ERROR);
	}
	else if ((*str)->len + 1 >= (*str)->capa)
	{
		result = ft_dobble_capa(str);
		if (result == ERROR)
			return (ERROR);
	}
	(*str)->s[(*str)->len] = c;
	(*str)->len++;
	(*str)->s[(*str)->len] = '\0';
	return (SUCCESS);
}

static int	ft_read_line(t_string *str, t_buf *buf, int fd)
{
	char	c;

	while (1)
	{
		c = ft_get_char(&buf, fd);
		if (c == ERROR || c == EOF)
		{
			ft_memset(buf->buf, 0, BUFFER_SIZE);
			buf->buf_ptr = buf->buf;
			buf->read_count = 0;
			if (c == ERROR)
				return (ERROR);
			break ;
		}
		if (ft_add_char(&str, c) == ERROR)
			return (ERROR);
		if (c == '\n')
			break ;
	}
	if (str->s > 0 && ft_add_char(&str, '\0') == SUCCESS)
		return (SUCCESS);
	return (EOF);
}

char	*get_next_line(int fd)
{
	t_string		str;
	static t_buf	buf;
	int				result;

	str.s = NULL;
	str.len = 0;
	str.capa = 0;
	result = ft_read_line(&str, &buf, fd);
	if (result != SUCCESS)
		return (ft_free_str(&str.s));
	return (str.s);
}
