/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:46:48 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 11:10:00 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftdlist.h"

void	ft_nodbinclear(t_dlist **lst, void (*del)(void *), int n)
{
	t_dlist	*tmp;
	t_dlist	**original;

	if (lst == NULL || del == NULL)
		return ;
	original = lst;
	while (*lst && n)
	{
		tmp = (*lst)->next;
		ft_nodbindelone(*lst, del);
		*lst = (t_dlist *)0;
		*lst = tmp;
		if (n > 0 && !--n)
			break ;
	}
	*original = NULL;
}
