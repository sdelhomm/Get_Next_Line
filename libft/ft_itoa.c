/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:01:10 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/14 19:12:44 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlo(int n)
{
	size_t i;

	i = 1;
	while ((n / 10) != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		i;

	len = intlo(n);
	i = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		i = -n;
		len++;
	}
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str[--len] = i % 10 + '0';
	while (i /= 10)
		str[--len] = i % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
