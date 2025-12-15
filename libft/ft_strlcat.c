/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaltaza <dbaltaza@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:16:52 by dbaltaza          #+#    #+#             */
/*   Updated: 2025/12/13 20:01:05 by dbaltaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src)
		return (0);
	dst_len = 0;
	src_len = 0;
	i = 0;
	while (dst_len < dstsize && dst[dst_len])
		dst_len++;
	while (src[src_len])
		src_len++;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	while (i < src_len && (dst_len + i) < (dstsize - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
