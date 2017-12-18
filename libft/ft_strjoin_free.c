/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:27:20 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/12/18 11:07:48 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	int		j;
	int		k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	str = malloc((k + j + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	free(s1);
	return (str);
}
