/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:14:00 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:56:56 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*str_end;
	char	ch;

	str_end = ft_strchr(str, '\0');
	ch = (unsigned char) c;
	if (ch == '\0')
		return (str_end);
	str_end--;
	while (*str)
	{
		if (*str_end == ch)
			return (str_end);
		str++;
		str_end--;
	}
	return (NULL);
}
