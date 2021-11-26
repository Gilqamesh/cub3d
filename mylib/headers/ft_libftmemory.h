#ifndef FT_LIBFTMEMORY_H
# define FT_LIBFTMEMORY_H

# include <stdlib.h>

// Writes 'n' zeroed bytes to the string 's'
void	ft_bzero(void *s, size_t n);
// Contiguously allocates enough space for 'nelem' objects that are 'elsize'
// bytes of memory each and returns a pointer to the allocated memory. The
// allocated memory is filled with bytes of value zero.
void	*ft_calloc(size_t nmemb, size_t size);
// Allocates and returns integer pointer to 'd'
int		*ft_intdup(int d);
// Copies bytes from string 'src' to string 'dest'. If the character 'c' occurs
// in the string 'src', the copy stops and a pointer to the byte after the copy
// of 'c' in the string 'dest' is returned. Otherwise, 'n' bytes are copied,
// and a NULL pointer is returned.
// If 'dest' and 'src' overlap, behavior is undefined.
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
// Locates the first occurrence of 'c' (converted to unsigned char) in string
// 's'. Returns a pointer to the byte located, NULL if no such byte exists
// within 'n' bytes.
void	*ft_memchr(const void *s, int c, size_t n);
// Compares byte string 's1' against byte string 's2'. Both strings are assumed
// to be 'n' bytes long. Returns 0 if the two strings are identical, otherwise
// the difference between the first two differing bytes (treated as unsigned
// char values)
int		ft_memcmp(const void *s1, const void *s2, size_t n);
// Copies 'n' bytes from memory area 'src' to memory area 'dest'.
// If 'dest' and 'src' overlap, behavior is undefined.
void	*ft_memcpy(void *dst, const void *src, size_t n);
// Copies 'n' bytes from string 'src' to string 'dest'. The two strings may
// overlap; the copy is always done in a non-destructive manner.
void	*ft_memmove(void *dest, const void *src, size_t n);
// Writes 'n' bytes of value 'c' to the string 's'
void	*ft_memset(void *b, int c, size_t len);

#endif /* FT_LIBFTMEMORY_H */