/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:08:19 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/15 19:14:34 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;
	int len1;
	int len2;
	int y;

	if (s1 == NULL || s2 == NULL)
		return ((int)NULL);
	y = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (len1 != len2)
		return (0);
	while (s1[i])
	{
		if (s1[i] == s2[i])
		{
			y++;
		}
		i++;
	}
	if (y == i)
		return (1);
	return (0);
}
