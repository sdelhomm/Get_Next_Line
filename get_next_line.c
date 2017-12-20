/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 10:00:23 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/12/20 09:27:10 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*stock_buffer(int fd)
{
	char	*buf;
	char	*cont;
	int		ret;
	int		buff_s;

	buff_s = BUFF_SIZE;
	if (!(buf = (char*)malloc(buff_s + 1 * sizeof(*buf))))
		return (NULL);
	if (!(cont = (char*)malloc(1 * sizeof(*buf))))
		return (NULL);
	cont[0] = '\0';
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		cont = ft_strjoin_free(cont, buf);
	}
	free(buf);
	return (cont);
}

static int		line_size(char *cont, size_t i, size_t len)
{
	size_t j;

	j = 0;
	if (i >= len)
		return (0);
	while (cont[i] != '\n' && cont[i])
	{
		j++;
		i++;
	}
	return (j);
}

static int		check_eof(char ***line, t_param *p)
{
	**line = NULL;
	if (p->i < p->len)
	{
		p->i++;
		**line = ft_strnew(0);
		if (p->i == p->len)
		{
			p->i = 0;
			p->nw = 0;
			ft_strdel(&p->cont);
		}
		return (1);
	}
	p->i = 0;
	p->nw = 0;
	ft_strdel(&p->cont);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_param	p[1024];
	char			*tmp;
	int				j;

	if (fd < 0 || line == NULL || fd >= 1024)
		return (-1);
	if (p[fd].nw == 0)
	{
		if (!(p[fd].cont = stock_buffer(fd)))
			return (-1);
		p[fd].nw = 1;
		p[fd].len = ft_strlen(p[fd].cont);
	}
	if (line_size(p[fd].cont, p[fd].i, p[fd].len) == 0)
		return (check_eof(&line, p + fd));
	if (!(tmp = ft_strnew((line_size(p[fd].cont, p[fd].i, p[fd].len) + 1))))
		return (-1);
	j = 0;
	while (p[fd].cont[p[fd].i] != '\n' && p[fd].cont[p[fd].i])
		tmp[j++] = p[fd].cont[p[fd].i++];
	p[fd].i++;
	tmp[j] = '\0';
	*line = tmp;
	return (1);
}
