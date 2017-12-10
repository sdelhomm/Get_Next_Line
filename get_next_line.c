/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 10:00:23 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/12/10 11:35:25 by sdelhomm         ###   ########.fr       */
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
	if (!(buf = (char*)malloc(buff_s * sizeof(*buf))))
		return (NULL);
	if (!(cont = (char*)malloc(32768 * sizeof(*cont))))
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		cont = ft_strcat(cont, buf);
	}
	free(buf);
	return (cont);
}

static int		line_size(char *cont, int i)
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

static int		check_eol(char ***line, t_param *p)
{
	**line = NULL;
	p->i++;
	if (p->cont[p->i])
	{
		return (1);
	}
	p->i = 0;
	p->nw = 0;
	return (0);
}

static int		check_eof(t_param *p)
{
	if (p->i <= ft_strlen(p->cont) + 1)
	{
		return (1);
	}
	p->i = 0;
	p->nw = 0;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_param	p;
	char			*tmp;
	int				j;

	if (fd < 0 || line == NULL)
		return (-1);
	if (p.nw == 0)
	{
		if (!(p.cont = stock_buffer(fd)))
			return (-1);
		p.nw = 1;
	}
	if (line_size(p.cont, p.i) == 0)
		return (check_eol(&line, &p));
	if (!(tmp = (char*)malloc((line_size(p.cont, p.i) + 1) * sizeof(*tmp))))
		return (-1);
	*line = tmp;
	j = 0;
	while (p.cont[p.i] != '\n' && p.cont[p.i])
		tmp[j++] = p.cont[p.i++];
	p.i++;
	tmp[j] = '\0';
	free(tmp);
	return (check_eof(&p));
}
