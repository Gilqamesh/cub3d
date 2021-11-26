#ifndef FT_LIBFTVALID_H
# define FT_LIBFTVALID_H

# include <stdbool.h>

// Returns true if 'str' is a valid Bash identifier, false otherwise.
bool	ft_isValidBashIdentifier(char *str);
// Returns true if 'str' is a valid C identifieer, false otherwise.
bool	ft_isValidCName(char *str);

#endif /* FT_LIBFTVALID_H */
