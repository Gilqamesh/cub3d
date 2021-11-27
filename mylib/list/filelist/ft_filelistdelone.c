/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelistdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:27:40 by edavid            #+#    #+#             */
/*   Updated: 2021/11/27 19:27:41 by edavid           ###   ########.fr       */
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
