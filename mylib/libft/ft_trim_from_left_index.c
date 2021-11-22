#include "libft.h"

/*
** Returns the first index in 'str' that is not part of 'set'
*/
int	ft_trim_from_left_index(char *str, char *set)
{
	bool	setChars[256];
	int		i;
	int		ret;

	if (str == NULL || set == NULL)
		return (0);
	i = -1;
	while (++i < 256)
		setChars[i] = false;
	i = -1;
	while (set[++i])
		setChars[(unsigned char)set[i]] = true;
	ret = 0;
	while (*str)
	{
		if (setChars[(unsigned char)*str] == false)
			return (ret);
		ret++;
		str++;
	}
	return (ret);
}
