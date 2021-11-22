#include "libft.h"
#include <stdlib.h>

static void	concatenateResult(char **result, t_node_binary *cur)
{
	int	result_index;
	int	curcontent_index;

	result_index = -1;
	while (cur)
	{
		curcontent_index = -1;
		while (((char **)cur->content)[++curcontent_index])
			result[++result_index] = ((char **)cur->content)[curcontent_index];
		cur = cur->prev;
	}
}

static int	strArrLen(char **strArr)
{
	int	len;

	if (strArr == NULL)
		return (0);
	len = 0;
	while (strArr[len])
		len++;
	return (len);
}

// Allocates and returns a NULL terminated string array that is the
// concatenation of going through the list's NULL terminated str array contents
char	**ft_nodbinstrarrjoin_from_back(t_node_binary *list)
{
	int				len;
	t_node_binary	*cur;
	char			**result;

	if (list == NULL)
	{
		result = malloc(sizeof(*result));
		result[0] = NULL;
		return (result);
	}
	len = 0;
	cur = list;
	while (cur)
	{
		len += strArrLen(cur->content);
		if (cur->next)
			cur = cur->next;
		else
			break ;
	}
	result = malloc((len + 1) * sizeof(*result));
	result[len] = NULL;
	concatenateResult(result, cur);
	return (result);
}
