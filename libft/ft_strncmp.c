/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:11:07 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/14 18:48:38 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while ((s1[i] || s2[i]) && j == 0)
	{
		if (s1[i] != s2[i] && i < n)
		{
			j = ((unsigned char)s1[i]) - ((unsigned char)s2[i]);
		}
		i++;
	}
	return (j);
}
