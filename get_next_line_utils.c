/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizusato <mizusato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:09:32 by mizusato          #+#    #+#             */
/*   Updated: 2024/06/25 13:27:33 by mizusato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_free_str(char **str)
{
	if (*str != NULL)
		free(*str);
	return (NULL);
}

int	ft_alloc_str(t_string **str)
{
	(*str)->s = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!((*str)->s))
		return (ERROR);
	(*str)->capa = BUFFER_SIZE + 1;
	return (SUCCESS);
}

int	ft_dobble_capa(t_string **str)
{
	char	*str_ptr;
	size_t	i;

	str_ptr = (*str)->s;
	(*str)->capa *= 2;
	(*str)->s = (char *)malloc((*str)->capa * sizeof(char));
	if (!((*str)->s))
	{
		free(str_ptr);
		return (ERROR);
	}
	i = 0;
	while (i < (*str)->len)
	{
		(*str)->s[i] = str_ptr[i];
		i++;
	}
	free(str_ptr);
	return (SUCCESS);
}
