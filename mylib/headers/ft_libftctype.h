#ifndef FT_LIBFTCTYPE_H
# define FT_LIBFTCTYPE_H

// Tests for any character for which isalpha or isdigit is true. (alphanum)
// Returns zero if the character tests false and 1 otherwise.
int	ft_isalnum(int c);
// Tests for any character for which isupper or islower is true. (alphabetical)
// Returns zero if the character tests false and returns 1 otherwise.
int	ft_isalpha(int c);
// Tests for an ASCII character, which is any character between 0 and octal
// 0177 inclusive. Returns 0 if the character tests false, 1 otherwise.
int	ft_isascii(int c);
// Returns 1 if c is a digit, 0 otherwise.
int	ft_isdigit(int c);
// Tests for any printing character, including space. The value of the argument
// must be representable as an unsigned char or the value of EOF.
// Returns zero if the character tests false, 1 otherwise.
int	ft_isprint(int c);
// Converts an upper-case letter to the corresponding lower-case letter. The
// argument must be representable as an unsigned char or the value of EOF.
// If the argument is an upper-case letter, it returns the corresponding
// lower-case letter if there is one; otherwise, the argument is returned
// unchanged.
int	ft_tolower(int c);
// Converts a lower-case letter to the corresponding upper-case letter. The
// argument must be representable as an unsigned char or the value of EOF.
// If the argument is a lower-case letter, it returns the corresponding
// upper-case letter if there is one; otherwise, the argument is returned
// unchanged.
int	ft_toupper(int c);

#endif /* FT_LIBFTCTYPE_H */
