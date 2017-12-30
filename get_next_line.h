/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 10:55:30 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/12/28 09:48:54 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE 42

typedef struct	s_param
{
	char	*cont;
	size_t	len;
	size_t	i;
	int		nw;
}				t_param;

# define PROTECT(Alloc) if (!Alloc) return (-1);

int				get_next_line(const int fd, char **line);

#endif
