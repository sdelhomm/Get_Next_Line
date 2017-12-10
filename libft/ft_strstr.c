/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:04:56 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/29 23:12:53 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *mdf, const char *aig)
{
	int i;
	int k;
	int len;

	i = 0;
	k = 0;
	len = ft_strlen(aig);
	if (aig[0] == '\0')
		return ((char*)mdf);
	while (mdf[i])
	{
		while (aig[k] == mdf[i + k])
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
