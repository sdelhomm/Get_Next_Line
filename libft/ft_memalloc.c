/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:12:37 by sdelhomm          #+#    #+#             */
/*   Updated: 2017/11/14 18:39:15 by sdelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int *m;

	m = (int*)malloc((size) * sizeof(*m));
	if (m == NULL)
		return (NULL);
	ft_memset(m, 0, size);
	return (m);
}
