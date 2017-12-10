/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:18:59 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/14 18:49:18 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		fin;

	fin = 0;
	i = 0;
	while (i < n)
	{
		if (src[i] && fin != 1)
			dest[i] = src[i];
		else
		{
			dest[i] = '\0';
			fin = 1;
		}
		i++;
	}
	return (dest);
}
