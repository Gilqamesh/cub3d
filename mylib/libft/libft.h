/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:05:13 by edavid            #+#    #+#             */
/*   Updated: 2021/09/05 13:54:16 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>
// Writes 'n' bytes of value 'c' to the string 's'
void			*ft_memset(void *s, int c, size_t n);
// Writes 'n' zeroed bytes to the string 's'
void			ft_bzero(void *s, size_t n);
// Copies 'n' bytes from memory area 'src' to memory area 'dest'.
// If 'dest' and 'src' overlap, behavior is undefined.
void			*ft_memcpy(void *dest, const void *src, size_t n);
// Copies bytes from string 'src' to string 'dest'. If the character 'c' occurs
// in the string 'src', the copy stops and a pointer to the byte after the copy
// of 'c' in the string 'dest' is returned. Otherwise, 'n' bytes are copied,
// and a NULL pointer is returned.
// If 'dest' and 'src' overlap, behavior is undefined.
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
// Copies 'n' bytes from string 'src' to string 'dest'. The two strings may
// overlap; the copy is always done in a non-destructive manner.
void			*ft_memmove(void *dest, const void *src, size_t n);
// Locates the first occurrence of 'c' (converted to unsigned char) in string
// 's'. Returns a pointer to the byte located, NULL if no such byte exists
// within 'n' bytes.
void			*ft_memchr(const void *s, int c, size_t n);
// Compares byte string 's1' against byte string 's2'. Both strings are assumed
// to be 'n' bytes long. Returns 0 if the two strings are identical, otherwise
// the difference between the first two differing bytes (treated as unsigned
// char values)
int				ft_memcmp(const void *s1, const void *s2, size_t n);
// Computes the length of string s.
size_t			ft_strlen(const char *s);
// Copies up to 'size' - 1 characters from 'src' to 'dst', NUL-terminating the
// result if 'size' is not 0. Return value is the total length of the string
// it tried to create.
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
// Appends 'src' to the end of 'dst' It will append at most
// 'size' - strlen(dst) - 1 characters. It will then NUL-terminate, unless
// 'size' is 0 or the original 'dst' string was lon ger than 'size'.
// Return value is the total length of the string it tried to create.
size_t			ft_strlcat(char *dst, const char *src, size_t size);
// Locates the first occurence of 'c' in the string pointed to by 's'. The
// terminating null character is conidered to be part of the string; therefore
// if c is '\0', the functions locates the terminating '\0'.
// Return value is the pointer to the located character, or NULL if the
// character does not appear in the string.
char			*ft_strchr(const char *s, int c);
// Locates the last occurence of 'c' in the string pointed to by 's'. The
// terminating null character is considered to be part of the string; therefore
// if c is '\0', the function locates the terminating '\0'.
// Return value is the pointer to the located character, or NULL if the
// character does not appear in the string.
char			*ft_strrchr(const char *s, int c);
// Locates the first occurence of the null-terminating string 'needle' in the
// string 'haystack', where not more than 'len' characters are searched.
// Characters that appear after a '\0' character are not searched.
// If needle is an empty string, haystack is returned; if needle occurs nowhere
// in haystack, NULL is returned; otherwise a pointer to the first character of
// the first occurence of needle is returned.
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
// Lexicographically compare the null-terminated string 's1' and 's2'.
// Compares not more than 'n' characters. Return an integer greater than, equal
// to, or less than 0, according as the string 's1' is greater than, equal to,
// or less than the string s2. The comparison is done using unsigned characters,
// so that '\200' is greaater than '\0'.
int				ft_strncmp(const char *s1, const char *s2, size_t n);
// Converts the initial portion of the string pointed to by 'nptr' to int
// representation. Returns INT_MAX or INT_MIN in case of overflow.
int				ft_atoi(const char *nptr);
// Tests for any character for which isupper or islower is true. (alphabetical)
// Returns zero if the character tests false and returns 1 otherwise.
int				ft_isalpha(int c);
// Returns 1 if c is a digit, 0 otherwise.
int				ft_isdigit(int c);
// Tests for any character for which isalpha or isdigit is true. (alphanum)
// Returns zero if the character tests false and 1 otherwise.
int				ft_isalnum(int c);
// Tests for an ASCII character, which is any character between 0 and octal
// 0177 inclusive. Returns 0 if the character tests false, 1 otherwise.
int				ft_isascii(int c);
// Tests for any printing character, including space. The value of the argument
// must be representable as an unsigned char or the value of EOF.
// Returns zero if the character tests false, 1 otherwise.
int				ft_isprint(int c);
// Converts a lower-case letter to the corresponding upper-case letter. The
// argument must be representable as an unsigned char or the value of EOF.
// If the argument is a lower-case letter, it returns the corresponding
// upper-case letter if there is one; otherwise, the argument is returned
// unchanged.
int				ft_toupper(int c);
// Converts an upper-case letter to the corresponding lower-case letter. The
// argument must be representable as an unsigned char or the value of EOF.
// If the argument is an upper-case letter, it returns the corresponding
// lower-case letter if there is one; otherwise, the argument is returned
// unchanged.
int				ft_tolower(int c);
// Contiguously allocates enough space for 'nelem' objects that are 'elsize'
// bytes of memory each and returns a pointer to the allocated memory. The
// allocated memory is filled with bytes of value zero.
void			*ft_calloc(size_t nelem, size_t elsize);
// Allocates sufficient memory for a copy of the string 's', does the copy,
// and returns a pointer to it. The pointer may subsequently be used as an
// argument to the function free. If insufficient memory is available, NULL
// is returned.
char			*ft_strdup(const char *s);
// Allocates and returns a substring from the string 's'
// The substring begins at the index 'start' and is of maximum size 'len'.
char			*ft_substr(char const *s, unsigned int start, size_t len);
// Allocates and returns a new string, which is the result of the
// concatenation of 's1' and 's2'.
char			*ft_strjoin(char const *s1, char const *s2);
// Allocates and returns a copy of 's1' with the characters specified in 'set'
// removed from the beginning and the end of the string.
char			*ft_strtrim(char const *s1, char const *set);
// Allocates and returns an array of strings obtained by splitting 's' using the
// character 'c' as a delimeter. The array ends with a NULL pointer.
// 200 words / sec ~
char			**ft_split(char const *s, char c);
// Allocates and returns an array of strings obtained by splitting 's' using the
// any of the characters in 'set' as delimeter.
// The array ends with a NULL pointer.
char			**ft_splitstr(char const *s, const char *set);
// Allocates and returns a string representing the integer received as an
// argument.
char			*ft_itoa(int n);
// Applies the function 'f' to each character of the string 's' to create a new
// string resulting from successive application of 'f'.
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// Outputs the character 'c' to the given file descriptor.
void			ft_putchar_fd(char c, int fd);
// Outputs the string 's' to the given file descriptor.
void			ft_putstr_fd(char *s, int fd);
// Outputs the string 's' to the given file descriptor, followed by a newline.
void			ft_putendl_fd(char *s, int fd);
// Outputs the integer 'n' to the given file descriptor.
void			ft_putnbr_fd(int n, int fd);
# ifndef T_LIST
#  define T_LIST
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
# endif
// Allocates and returns a new element. The variable 'content' is initialized
// with the value of the parameter 'content'. The variable 'next' is
// initialized to NULL.
t_list			*ft_lstnew(void *content);
// Adds the element 'new' at the beginning of the list.
void			ft_lstadd_front(t_list **lst, t_list *new);
// Counts the number of elements in the list.
int				ft_lstsize(t_list *lst);
// Returns the last element of the list.
t_list			*ft_lstlast(t_list *lst);
// Adds the element 'new' at the end of the list.
void			ft_lstadd_back(t_list **lst, t_list *new);
// Takes as a parameter an element and frees the memory of the element's
// content using the function 'del' given as a parameter and free the element.
// The memory of 'next' is not freed.
void			ft_lstdelone(t_list *lst, void (*del)(void *));
// Deletes and frees the given element and every successor of that element,
// using the function 'del' and free.
// Finally, the pointer to the list is set to NULL.
void			ft_lstclear(t_list **lst, void (*del)(void *));
// Iterates the list 'lst' and applies the function 'f' to the content of each
// element.
void			ft_lstiter(t_list *lst, void (*f)(void *));
// Iterates the list 'lst' and applies the function 'f' to the content of each
// element. Creates a new list resulting of the successive application of the
// function 'f'. The 'del' function is used to delete the content of an element
// if needed.
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
// inserts 'new' into 'lst' in a way that *(int *) 'content' is in ascending
// order
void			ft_lstsortedinsert_int(t_list **lst, t_list *new);
// Frees node->content and node, where node is of type *t_list
void			ft_lstdel(void *node);
// Prints out the contents of list, up to 'n' times, if 'n' is negative,
// the functions prints out the entire list.
void			ft_lstprint_int(t_list *lst, int n);
# ifndef T_NODE_BINARY
#  define T_NODE_BINARY
typedef struct s_node_binary
{
	void					*content;
	struct s_node_binary	*next;
	struct s_node_binary	*prev;
}	t_node_binary;
# endif
// Allocates and returns a new element. The variable 'content' is initialized
// with the value of the parameter 'content'. The variable 'next' and 'prev' is
// initialized to NULL.
t_node_binary	*ft_nodbinnew(void *content);
// Adds the element 'new' at the beginning of the list.
void			ft_nodbinadd_front(t_node_binary **lst, t_node_binary *new);
// Counts the number of elements in the list.
int				ft_nodbinsize(t_node_binary *lst);
// Returns the last element of the list.
t_node_binary	*ft_nodbinlast(t_node_binary *lst);
// Adds the element 'new' at the end of the list. Sets new->prev to the
// pointer of the element for the last one.
void			ft_nodbinadd_back(t_node_binary **lst, t_node_binary *new);
// Takes as a parameter an element and frees the memory of the element's
// content using the function 'del' given as a parameter and free the element.
// The memory of 'next' is not freed.
void			ft_nodbindelone(t_node_binary *lst, void (*del)(void *));
// Deletes and frees the given element and every successor of that element,
// using the function 'del' and free up to 'n' elements or if 'n' is negative
// until (*lst)->next is NULL.
// Finally, the pointer to the list is set to NULL.
void			ft_nodbinclear(t_node_binary **lst, void (*del)(void *), int n);
// Iterates the list 'lst' and applies the function 'f' to the content of each
// element.
void			ft_nodbiniter(t_node_binary *lst, void (*f)(void *));
// Iterates the list 'lst' and applies the function 'f' to the content of each
// element. Creates a new list resulting of the successive application of the
// function 'f'. The 'del' function is used to delete the content of an element
// if needed.
t_node_binary	*ft_nodbinmap(t_node_binary *lst, void *(*f)(void *),
					void (*del)(void *));
// Prints out the contents of list, up to 'n' times, if 'n' is negative,
// the functions prints out the entire list.
void			ft_nodbinprint_int(t_node_binary *lst, int n);
// Frees node->content and node, where node is of type *t_node_binary
void			ft_nodbindel(void *node);
// inserts 'new' into 'lst' in a way that *(int *) 'content' is in ascending
// order
void			ft_nodbinsortedinsert_int(t_node_binary **lst, t_node_binary *new);
# ifndef T_2_INT
#  define T_2_INT
typedef struct s_2_int
{
	int	a;
	int	b;
}	t_2_int;
# endif
# ifndef T_3_INT
#  define T_3_INT
typedef struct s_3_int
{
	int	a;
	int	b;
	int	c;
}	t_3_int;
# endif
// Uses merge sort algorithm to sort 'array' from 'start_index' to 'end_index'
// with the help of 'helper_array' that must be at least size of
// end_index - start_index
// Ex. usage: int arr[10], int helper[10]
// ft_merge_sort_int(arr, (t_2_int){0, 10}, helper);
void			ft_merge_sort_int(int *array, t_2_int start_end_indexes,
					int *helper);
// Returns the absolute value of an integer. INT_MIN -> INT_MAX
int				ft_abs_int(int a);
// Lexicographically compare the null-terminated strings 's1' and 's2'. 
// Return an integer greater than, equal to, or less than 0, according as the
// string 's1' is greater than, equal to, or less than the string 's2'. 
// The comparison is done using unsigned characters, so that '\200' is greater
// than '\0'.
int				ft_strcmp(const char *s1, const char *s2);
// Uses merge sort algorithm to sort 'array' from 'start_index' to 'end_index'
// with the help of 'helper_array' that must be at least size of
// end_index - start_index
// Ex. usage: char *arr[10], int *helper[10]
// ft_merge_sort_str(arr, (t_2_int){0, 10}, helper);
void			ft_merge_sort_str(char **array, t_2_int start_end_indexes,
					char **helper_array);
// Allocates and returns integer pointer to 'd'
int				*ft_intdup(int d);
// Prints 'n' integers from 'arr' as integers
void			ft_printintarr(int *arr, int n);
// Returns the number of digits in 'd'
int				ft_intlen(int d);
// Returns the minimum integer out of 'a' and 'b'
int				ft_minofint(int a, int b);
// Writes string 's' up to 'n' characters to 'fd' file descriptor
void			ft_putnstr_fd(char *s, int n, int fd);
// Returns the maximum integer out of 'a' and 'b'
int				ft_maxofint(int a, int b);
// Returns the number of digits in 'n' after converted to 'base' > 1
int				ft_baselen(unsigned long n, int base);
// Converts 'n' to 'base' > 1 and returns the allocated string
char			*ft_itobase(unsigned long n, int base);
// Counts the number of words in 's' with a delimiter character of 'c'
int				ft_n_of_words_by_delim(char *s, char c);
// Frees the char **str array and sets it to NULL
void			ft_destroy_str_arr(char ***str);
// Allocates and returns a string that is the concatenation of going through
// the list's str contents
char			*ft_nodbinstrjoin_from_back(t_node_binary *list);
// Allocates and returns a NULL terminated string array that is the
// concatenation of going through the list's NULL terminated str array contents
char			**ft_nodbinstrarrjoin_from_back(t_node_binary *list);
// Allocates and returns a NULL terminated string array that is the
// concatenation of going through the list's str contents
char			**ft_nodbinstr_to_strarr(t_node_binary *list);
// Free all addresses stored in 'lst' then clears lst and sets
// it to NULL
void			ft_lstmallocfree(t_list **lst);
// Malloc instead it also adds the address into 'lst'
// Use ft_lstmallocfree to free all the saved addresses
void			*ft_lstmallocwrapper(t_list **lst, size_t size, bool is_calloc);
// Returns the first index in 'str' that is not part of 'set'
int				ft_trim_from_left_index(char *str, char *set);
// Returns the first index in 'str' that is not part of 'set'
int				ft_trim_from_right_index(char *str, char *set);
// Returns true if 'str' only consists of alphanumeric characters.
bool			ft_isStrAlphaNumeric(char *str);
// Returns true if 'str' is a valid C identifieer, false otherwise.
bool			ft_isValidCName(char *str);
// Returns true if 'str' is a valid Bash identifier, false otherwise.
bool			ft_isValidBashIdentifier(char *str);
// Returns true if 'str' is contained in the NULL terminated 'strArr'.
bool			ft_isStrContainedInStrArr(char *str, char **strArr);
# ifndef T_OBJ_LST
#  define T_OBJ_LST
typedef struct s_obj_lst
{
	char	*key;
	char	*value;
	struct s_obj_lst	*next;
}	t_obj_lst;
# endif
// Finds the str 'key' in the list 'head' and returns the address to it.
t_obj_lst		*ft_objlst_findbykey(t_obj_lst *head, char *key);
// Adds the element 'new' at the beginning of the list.
void			ft_objlstadd_front(t_obj_lst **lst, t_obj_lst *new);
// Allocates and returns a new element t_obj_lst *result;
t_obj_lst		*ft_objlst_new(char *key, char *value);
// Works like the function 'ft_strdup' but only copies the 'str' until the first
// matching of char 'c' in 'str'.
char			*ft_strdupchr(char *str, char c);
// Creates a list using the NULL terminated 'strArr' and returns a pointer to it
// In reverse order, using ft_objlst_front.
t_obj_lst		*ft_objlst_mapFromEnv(char **strArr);
// Frees the list using the function 'del' and free.
// Finally, the pointer to the list is set to NULL.
void			ft_objlst_clear(t_obj_lst **lst, void (*del)(void *));
// Applies the function 'del' on 'lst'.
// The memory of 'next' is not freed.
void			ft_objlst_delone(t_obj_lst *lst, void (*del)(void *));
// Frees node->content and node, where node is of type *t_obj_lst
void			ft_objlst_del(void *node);
// Find 'node' in t_obj_lst 'lst' and deletes it keeping the rest of the list
// intact.
void			ft_objlst_rem(t_obj_lst **lst, t_obj_lst *node);
// Inserts the element 'new' to 'lst' by the alphabetical ordering of new->key.
void			ft_objlstinsert(t_obj_lst **lst, t_obj_lst *new);
# ifndef T_FILELST
#  define T_FILELST
enum e_redirection_mode
{
	REDIR_VOID,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
	REDIR_NONE
};
typedef struct s_filelst
{
	char					*filename;
	enum e_redirection_mode	mode;
	struct s_filelst		*next;
}	t_filelst;
# endif
// Adds the element 'new' at the end of the list.
void			ft_filelstadd_back(t_filelst **lst, t_filelst *new);
// Frees the list using the function 'del'.
// Finally, the pointer to the list is set to NULL.
void			ft_filelstclear(t_filelst **lst, void (*del)(void *));
// Frees memory associated with 'node' that is of t_filelst* type.
void			ft_filelstdel(void *node);
// Applies the function 'del' on 'lst'.
// The memory of 'next' is not freed.
void			ft_filelstdelone(t_filelst *lst, void (*del)(void *));
// Allocates and returns a new element t_filelst *result;
t_filelst		*ft_filelstnew(char *filename, int mode);
// Allocates and returns a NULL terminated str array that has 'str' as its
// first element.
char			**ft_strToStrArr(char *str);
// Returns true if 'str' is a valid number.
// ex of valid strings: "-234", "+3432"
// ex of not valid strings: "--32", "234a"
bool			ft_isStrNumber(char *str);
// Install 'nullable_ptr' by passing it as an argument first time calling this
// function. Anytime the function called afterwards it will return the installed
// pointer.
void			*ft_get_ptr(void *nullable_ptr);

#endif
