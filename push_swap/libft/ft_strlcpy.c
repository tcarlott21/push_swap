/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:05:39 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:56:33 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (src[i])
		i++;
	if (dstsize)
	{
		while (n < (dstsize - 1) && src[n] != '\0')
		{
			dst[n] = src[n];
			n++;
		}
		dst[n] = '\0';
	}
	return (i);
}
/*int main(void)
{
	char a[] = "abcd";
	char b[] = "cv ffdfdfdddf ";
	size_t i;
	i = 2;
	printf("%zu\n", ft_strlcpy(a, b, i));
	printf("%lu\n", strlcpy(a, b, i));
	printf("%s\n", a);
}*/
