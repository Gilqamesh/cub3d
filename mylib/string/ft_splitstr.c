/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:51:06 by edavid            #+#    #+#             */
/*   Updated: 2021/11/26 15:28:54 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libftstring.h"
#include "ft_libftslist.h"

static char	**pointerToStr(char const *s)
{
	char	**ptr;

	ptr = malloc(2 * sizeof(*ptr));
	ptr[0] = ft_strdup(s);
	ptr[1] = NULL;
	return (ptr);
}

static void	mapLstToStrArr(t_list *lst, char **strArr)
{
	t_list	*cur;
	int		i;

	cur = lst;
	i = 0;
	while (cur)
	{
		strArr[i++] = (char *)cur->content;
		cur = cur->next;
	}
	strArr[i] = NULL;
}

static void	deleteNodes(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

static void	initLst(bool *setChars, t_list **tokens, char const *s)
{
	char	*prev;
	char	*cur;

	prev = (char *)s;
	cur = prev;
	while (*cur)
	{
		if (setChars[(unsigned char)*cur])
		{
			if (cur != prev)
				ft_lstadd_back(tokens, ft_lstnew(ft_substr(prev, 0,
							cur - prev)));
			prev = ++cur;
		}
		else
		{
			cur++;
			if (!*cur)
				ft_lstadd_back(tokens, ft_lstnew(ft_substr(prev, 0,
							cur - prev)));
		}
	}
}

char	**ft_splitstr(char const *s, const char *set)
{
	bool	setChars[256];
	int		i;
	t_list	*tokens;
	char	**tokenArray;

	if (s == NULL)
		return (NULL);
	if (set == NULL)
		return (pointerToStr(s));
	i = -1;
	while (++i < 256)
		setChars[i] = false;
	i = -1;
	while (set[++i])
		setChars[(unsigned char)set[i]] = true;
	tokens = NULL;
	initLst(setChars, &tokens, s);
	tokenArray = malloc((ft_lstsize(tokens) + 1) * sizeof(*tokenArray));
	mapLstToStrArr(tokens, tokenArray);
	deleteNodes(tokens);
	return (tokenArray);
}
