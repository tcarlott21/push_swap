/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlott <tcarlott@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:07:01 by aclarita          #+#    #+#             */
/*   Updated: 2022/05/10 14:54:56 by tcarlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lnew;

	lnew = (t_list *) malloc(sizeof(t_list));
	if (!lnew)
		return (0);
	(*lnew).content = content;
	lnew->next = NULL;
	return (lnew);
}
