/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:11:13 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/14 19:13:29 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nouvsize(char const *str)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = 0;
	while ((str[len - 1] == ' ' || str[len - 1] == '\n' ||
				str[len - 1] == '\t') && str[i])
	{
		len--;
	}
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && str[i])
	{
		i++;
		len--;
	}
	if (len <= 0)
		len = 0;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		max;
	int		y;

	if (s == NULL)
		return (NULL);
	y = 0;
	str = (char*)malloc((nouvsize(s) + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i--;
	max = i;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if ((max == (ft_strlen(s) - 1)) && i == 0)
		return (ft_strcpy(str, s));
	while (i <= max)
		str[y++] = s[i++];
	str[y] = '\0';
	return (str);
}
