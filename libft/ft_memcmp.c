/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:38:03 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/14 18:40:49 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < n && j == 0)
	{
		if (((char*)s1)[i] != ((char*)s2)[i] && i < n)
		{
			j = ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i];
		}
		i++;
	}
	return (j);
}
