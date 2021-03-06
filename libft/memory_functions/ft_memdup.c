/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:41:58 by fsabatie          #+#    #+#             */
/*   Updated: 2018/01/25 14:51:28 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *src, size_t len)
{
	unsigned char	*res;

	if (!(res = (unsigned char*)malloc(sizeof(unsigned char) * len)))
		return (NULL);
	ft_memcpy(res, src, len);
	return (res);
}
