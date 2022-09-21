/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:19:43 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:57:01 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = 0;
	if (s1 && set)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (end > start && ft_strchr(set, s1[end - 1]))
			end--;
		str = (char *) malloc(end - start + 1);
		if (!str)
			return (0);
		ft_strlcpy(str, &s1[start], end - start + 1);
	}
	return (str);
}
/*int main()
{
	char a[] = "abababa";
	char b[] = "ab";
	printf("%s", ft_strtrim(a,b));
}*/
