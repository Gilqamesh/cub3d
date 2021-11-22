/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objlst_mapFromEnv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:49:39 by edavid            #+#    #+#             */
/*   Updated: 2021/09/10 18:31:40 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Creates a list using the NULL terminated 'strArr' and returns a pointer to it
** In reverse order, using ft_objlst_front.
*/
t_obj_lst	*ft_objlst_mapFromEnv(char **strArr)
{
	t_obj_lst	*lst;
	int			i;
	char		*key;
	char		*value;

	if (strArr == NULL)
		return (NULL);
	lst = NULL;
	i = -1;
	while (strArr[++i])
	{
		key = ft_strdupchr(strArr[i], '=');
		value = ft_strchr(strArr[i], '=');
		if (value)
			value = ft_substr(value + 1, 0, ft_strlen(strArr[i])
					- ft_strlen(key) - 1);
		ft_objlstadd_front(&lst, ft_objlst_new(key, value));
	}
	return (lst);
}
