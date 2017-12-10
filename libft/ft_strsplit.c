/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:23:29 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/14 19:13:10 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *str, char c)
{
	int mots;
	int i;

	i = 0;
	mots = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			mots++;
		i++;
	}
	if (str[0] != c)
		mots++;
	return (mots);
}

static char	*ft_fill(char const *str, char c, int i, int *o)
{
	char	*sm;
	int		k;

	k = 0;
	sm = (char *)malloc((ft_strlen(str) * sizeof(sm)));
	if (sm == NULL)
		return (NULL);
	while (str[i] != c && str[i])
	{
		sm[k] = str[i];
		k++;
		i++;
	}
	sm[k] = '\0';
	while (str[i] == c && str[i])
		i++;
	*o = i;
	return (sm);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		mots;
	char	**str;
	int		o;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	mots = ft_count(s, c);
	str = (char**)malloc(sizeof(str) * (mots + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] == c)
		i++;
	while (j < mots && s[i])
	{
		str[j] = ft_fill(s, c, i, &o);
		i = o;
		j++;
	}
	str[j] = NULL;
	return (str);
}
