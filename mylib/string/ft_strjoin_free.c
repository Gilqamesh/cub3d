#include "ft_libftstring.h"

static char	*strjoin_return_helper(char *s1, char *s2)
{
	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	return ((char *)0);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;
	char	*r;
	char	*tmp;

	if (!s1 || !s2)
		return (strjoin_return_helper(s1, s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(s1_len + s2_len + 1);
	if (!new)
		return ((char *)0);
	r = new;
	tmp = s1;
	while (s1_len--)
		*r++ = *tmp++;
	free(s1);
	tmp = s2;
	while (s2_len--)
		*r++ = *tmp++;
	free(s2);
	*r = '\0';
	return (new);
}
