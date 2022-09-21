/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:14:08 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:56:28 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	destsize;
	size_t	srcsize;

	i = 0;
	n = 0;
	destsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (dstsize <= destsize)
		return (dstsize + srcsize);
	while (dst[n])
		n++;
	while ((destsize + i) < (dstsize - 1) && src[i])
	{
		dst[n] = src[i];
		n++;
		i++;
	}
	dst[n] = '\0';
	return (destsize + srcsize);
}
/*int main(void)
{
	char *a = "hell";
	const char *b = "abcd";
	size_t i;
	i = 5;
//	printf("%zu\n", ft_strlcat(a, b, i));
	printf("%zu\n", strlcat(a, b, i));
	printf("%s\n", a);
	printf("%s\n", b);
}*/
