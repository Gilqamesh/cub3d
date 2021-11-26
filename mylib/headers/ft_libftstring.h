#ifndef FT_LIBFTSTRING_H
# define FT_LIBFTSTRING_H

# include <stdbool.h>
# include <stdlib.h>

// Converts the initial portion of the string pointed to by 'nptr' to int
// representation. Returns INT_MAX or INT_MIN in case of overflow.
int		ft_atoi(const char *nptr);
// Frees the char **str array and sets it to NULL
void	ft_destroy_str_arr(char ***str);
// Returns true if 'str' only consists of alphanumeric characters.
bool	ft_isStrAlphaNumeric(char *str);
// Returns true if 'str' is contained in the NULL terminated 'strArr'.
bool	ft_isStrContainedInStrArr(char *str, char **strArr);
// Returns true if 'str' is a valid number.
// ex of valid strings: "-234", "+3432"
// ex of not valid strings: "--32", "234a"
bool	ft_isStrNumber(char *str);
// Allocates and returns a string representing the integer received as an
// argument.
char	*ft_itoa(int n);
// Converts 'n' to 'base' > 1 and returns the allocated string
char	*ft_itobase(unsigned long n, int base);
// Counts the number of words in 's' with a delimiter character of 'c'
int		ft_n_of_words_by_delim(char *s, char c);
// Allocates and returns an array of strings obtained by splitting 's' using the
// character 'c' as a delimeter. The array ends with a NULL pointer.
// 200 words / sec ~
char	**ft_split(char const *s, char c);
// Allocates and returns an array of strings obtained by splitting 's' using the
// any of the characters in 'set' as delimeter.
// The array ends with a NULL pointer.
char	**ft_splitstr(char const *s, const char *set);
// Locates the first occurence of 'c' in the string pointed to by 's'. The
// terminating null character is conidered to be part of the string; therefore
// if c is '\0', the functions locates the terminating '\0'.
// Return value is the pointer to the located character, or NULL if the
// character does not appear in the string.
char	*ft_strchr(const char *s, int c);
// Lexicographically compare the null-terminated strings 's1' and 's2'. 
// Return an integer greater than, equal to, or less than 0, according as the
// string 's1' is greater than, equal to, or less than the string 's2'. 
// The comparison is done using unsigned characters, so that '\200' is greater
// than '\0'.
int		ft_strcmp(const char *s1, const char *s2);
// Allocates sufficient memory for a copy of the string 's', does the copy,
// and returns a pointer to it. The pointer may subsequently be used as an
// argument to the function free. If insufficient memory is available, NULL
// is returned.
char	*ft_strdup(const char *s);
// Works like the function 'ft_strdup' but only copies the 'str' until the first
// matching of char 'c' in 'str'.
char	*ft_strdupchr(char *str, char c);
// Works like strjoin but frees 's1' and 's2'
char	*ft_strjoin_free(char *s1, char *s2);
// Allocates and returns a new string, which is the result of the
// concatenation of 's1' and 's2'.
char	*ft_strjoin(char const *s1, char const *s2);
// Appends 'src' to the end of 'dst' It will append at most
// 'size' - strlen(dst) - 1 characters. It will then NUL-terminate, unless
// 'size' is 0 or the original 'dst' string was lon ger than 'size'.
// Return value is the total length of the string it tried to create.
size_t	ft_strlcat(char *dst, const char *src, size_t size);
// Copies up to 'size' - 1 characters from 'src' to 'dst', NUL-terminating the
// result if 'size' is not 0. Return value is the total length of the string
// it tried to create.
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
// Computes the length of string s.
size_t	ft_strlen(const char *s);
// Applies the function 'f' to each character of the string 's' to create a new
// string resulting from successive application of 'f'.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Lexicographically compare the null-terminated string 's1' and 's2'.
// Compares not more than 'n' characters. Return an integer greater than, equal
// to, or less than 0, according as the string 's1' is greater than, equal to,
// or less than the string s2. The comparison is done using unsigned characters,
// so that '\200' is greaater than '\0'.
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// Locates the first occurence of the null-terminating string 'needle' in the
// string 'haystack', where not more than 'len' characters are searched.
// Characters that appear after a '\0' character are not searched.
// If needle is an empty string, haystack is returned; if needle occurs nowhere
// in haystack, NULL is returned; otherwise a pointer to the first character of
// the first occurence of needle is returned.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
// Locates the last occurence of 'c' in the string pointed to by 's'. The
// terminating null character is considered to be part of the string; therefore
// if c is '\0', the function locates the terminating '\0'.
// Return value is the pointer to the located character, or NULL if the
// character does not appear in the string.
char	*ft_strrchr(const char *s, int c);
// Allocates and returns a NULL terminated str array that has 'str' as its
// first element.
char	**ft_strToStrArr(char *str);
// Allocates and returns a copy of 's1' with the characters specified in 'set'
// removed from the beginning and the end of the string.
char	*ft_strtrim(char const *s1, char const *set);
// Allocates and returns a substring from the string 's'
// The substring begins at the index 'start' and is of maximum size 'len'.
char	*ft_substr(char const *s, unsigned int start, size_t len);
// Returns the first index in 'str' that is not part of 'set'
int		ft_trim_from_left_index(char *str, char *set);
// Returns the first index in 'str' that is not part of 'set'
int		ft_trim_from_right_index(char *str, char *set);

#endif /* FT_LIBFTSTRING_H */
