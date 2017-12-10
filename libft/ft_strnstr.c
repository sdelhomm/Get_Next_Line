/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:56:22 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/16 19:03:15 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *mdf, const char *aig, size_t n)
{
	size_t i;
	size_t k;
	size_t len;

	i = 0;
	k = 0;
	len = ft_strlen(aig);
	if (aig[0] == '\0')
		return ((char*)mdf);
	while (i < n && mdf[i])
	{
		while (aig[k] == mdf[i + k] && (k + i) < n && mdf[i + k])
		{
			if (k == len - 1)
				return ((char*)mdf + i);
			k++;
		}
		k = 0;
		i++;
	}
	return (0);
}
