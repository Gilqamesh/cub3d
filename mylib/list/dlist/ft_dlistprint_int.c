/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistprint_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:32:11 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 20:10:51 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftdlist.h"
#include "ft_libftprint.h"

void	ft_nodbinprint_int(t_dlist *lst, int n)
{
	if (!lst)
	{
		ft_printf("List is empty.\n");
		return ;
	}
	ft_printf("List: ");
	while (lst && n)
	{
		ft_printf("%d ", *(int *)lst->content);
		lst = lst->next;
		if (n > 0 && !--n)
			break ;
	}
	ft_printf("\n");
}
