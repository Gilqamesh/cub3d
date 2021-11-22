/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_delone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:30:48 by edavid            #+#    #+#             */
/*   Updated: 2021/09/10 18:42:44 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function 'del' on 'lst'.
** The memory of 'next' is not freed.
*/
void	ft_objlst_delone(t_obj_lst *lst, void (*del)(void *))
{
	(*del)(lst);
}
