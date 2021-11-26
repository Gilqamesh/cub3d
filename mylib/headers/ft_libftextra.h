#ifndef FT_LIBFTEXTRA_H
# define FT_LIBFTEXTRA_H

// Install 'nullable_ptr' by passing it as an argument first time calling this
// function. Anytime the function called afterwards it will return the installed
// pointer.
void	*ft_get_ptr(void *nullable_ptr);

#endif /* FT_LIBFTEXTRA_H */
