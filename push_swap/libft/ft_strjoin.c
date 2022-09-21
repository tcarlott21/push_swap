/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:45:40 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:56:21 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	sjoin_len;

	if (!s1 || !s2)
		return (0);
	sjoin_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(sjoin_len);
	if (!strjoin)
		return (0);
	ft_strlcpy(strjoin, s1, ft_strlen(s1) + 1);
	ft_strlcat(strjoin, s2, sjoin_len);
	return (strjoin);
}
