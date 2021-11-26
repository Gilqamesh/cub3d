/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelistdelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:19:02 by edavid            #+#    #+#             */
/*   Updated: 2021/09/13 14:19:28 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftfilelist.h"

/*
** Applies the function 'del' on 'lst'.
** The memory of 'next' is not freed.
*/
void	ft_filelistdelone(t_filelist *lst, void (*del)(void *))
{
	(*del)(lst);
}
