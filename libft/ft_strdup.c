/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:57:22 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/14 15:00:06 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*new;
	int		l;

	l = ft_strlen(src);
	new = (char*)malloc((l + 1) * sizeof(*src));
	i = 0;
	if (new == NULL)
		return (NULL);
	while (i < l)
	{
		new[i] = src[i];
		i++;
	}
	new[l] = '\0';
	return (new);
}
