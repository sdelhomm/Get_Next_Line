/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:54:25 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/15 19:28:53 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		over(int k, int nega, int j)
{
	if (k >= 20)
	{
		if (nega == 1)
			return (0);
		return (-1);
	}
	if (nega == 1)
		return (-j);
	return (j);
}

int				ft_atoi(const char *str)
{
	int i[4];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	i[3] = 0;
	while (str[i[0]] == ' ' || str[i[0]] == '\t' || str[i[0]] == '\n' ||
			str[i[0]] == '\v' || str[i[0]] == '\f' || str[i[0]] == '\r')
		i[0] = i[0] + 1;
	if (str[i[0]] == '-')
		i[1] = 1;
	if (str[i[0]] == '+' || str[i[0]] == '-')
		i[0] = i[0] + 1;
	if (str[i[0]] > 47 && str[i[0]] < 58)
	{
		while (str[i[0]] > 47 && str[i[0]] < 58)
		{
			i[2] = (i[2] * 10) + (str[i[0]++] - 48);
			i[3]++;
		}
		if (i[1] == 1)
			return (over(i[3], i[1], i[2]));
		return (over(i[3], i[1], i[2]));
	}
	return (0);
}
