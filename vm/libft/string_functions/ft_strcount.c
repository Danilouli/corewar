/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:00:11 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:54:21 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcount(char *haystack, char needle)
{
	int		i;
	size_t	c;

	c = 0;
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle)
			c++;
		i++;
	}
	return (c);
}
