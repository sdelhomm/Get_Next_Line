/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 10:00:23 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/28 14:47:48 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char*)s)[i] = '\0';
		i++;
	}
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int ldest;

	i = 0;
	ldest = ft_strlen(dest);
	while (src[i])
	{
		dest[ldest] = src[i];
		ldest++;
		i++;
	}
	dest[ldest] = '\0';
	return (dest);
}

char	*stock_buffer(int fd)
{
	char	*buf;
	char	*cont;
	int		ret;
	int		buff_s;

	buff_s = BUFF_SIZE;
	buf = (char*)malloc(buff_s * sizeof(*buf));
	if (buf == NULL)
		return (NULL);
	cont = (char*)malloc((255 * buff_s) * sizeof(*cont));
	if (cont == NULL)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		cont = ft_strcat(cont, buf);
	}
	free(buf);
	return (cont);
}

int		line_size(char *cont, int i)
{
	int j;

	j = 0;
	while (cont[i] != '\n' && cont[i])
	{
		j++;
		i++;
	}
	return (j);
}

int		get_next_line(int fd, char **line)
{
	static int		i;
	static char		*cont;
	static int		ncella;
	char			*tmp;
	int				j;

	if (ncella == 0)
	{
		cont = stock_buffer(fd);
		ncella = 1;
	}
	if (line_size(cont, i) == 0)
	{
		*line = NULL;
		if (cont[i])
		{
			i++;
			return (1);
		}
		i = 0;
		ncella = 0;
		ft_bzero(cont, ft_strlen(cont));
		return (0);
	}
	tmp = (char*)malloc((line_size(cont, i) + 1) * sizeof(*tmp));
	if (tmp == NULL)
		return (-1);
	*line = tmp;
	j = 0;
	while (cont[i] != '\n' && cont[i])
		tmp[j++] = cont[i++];
	i++;
	tmp[j] = '\0';
	free(tmp);
	if (i <= ft_strlen(cont))
		return (1);
	i = 0;
	ncella = 0;
	ft_bzero(cont, ft_strlen(cont));
	return (0);
}