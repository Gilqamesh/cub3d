#ifndef FT_LIBFTDLIST_H
# define FT_LIBFTDLIST_H

typedef struct s_dlist
{
	void					*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

# include <stdlib.h>

// Adds the element 'new' at the end of the list. Sets new->prev to the
// pointer of the element for the last one.
void	ft_nodbinadd_back(t_dlist **lst, t_dlist *new);
// Adds the element 'new' at the beginning of the list.
void	ft_nodbinadd_front(t_dlist **lst, t_dlist *new);
// Deletes and frees the given element and every successor of that element,
// using the function 'del' and free up to 'n' elements or if 'n' is negative
// until (*lst)->next is NULL.
// Finally, the pointer to the list is set to NULL.
void	ft_nodbinclear(t_dlist **lst, void (*del)(void *), int n);
// Frees node->content and node, where node is of type *t_node_binary
void	ft_nodbindel(void *node);
// Takes as a parameter an element and frees the memory of the element's
// content using the function 'del' given as a parameter and free the element.
// The memory of 'next' is not freed.
void	ft_nodbindelone(t_dlist *lst, void (*del)(void *));
// Iterates the list 'lst' and applies the function 'f' to the content of each
// element.
void	ft_nodbiniter(t_dlist *lst, void (*f)(void *));
// Returns the last element of the list.
t_dlist	*ft_nodbinlast(t_dlist *lst);
// Iterates the list 'lst' and applies the function 'f' to the content of each
// element. Creates a new list resulting of the successive application of the
// function 'f'. The 'del' function is used to delete the content of an element
// if needed.
t_dlist	*ft_nodbinmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *));
// Allocates and returns a new element. The variable 'content' is initialized
// with the value of the parameter 'content'. The variable 'next' and 'prev' is
// initialized to NULL.
t_dlist	*ft_nodbinnew(void *content);
// Prints out the contents of list, up to 'n' times, if 'n' is negative,
// the functions prints out the entire list.
void	ft_nodbinprint_int(t_dlist *lst, int n);
// Counts the number of elements in the list.
int		ft_nodbinsize(t_dlist *lst);
// inserts 'new' into 'lst' in a way that *(int *) 'content' is in ascending
// order
void	ft_nodbinsortedinsert_int(t_dlist **lst, t_dlist *new);
// Allocates and returns a NULL terminated string array that is the
// concatenation of going through the list's str contents
char	**ft_nodbinstr_to_strarr(t_dlist *list);
// Allocates and returns a NULL terminated string array that is the
// concatenation of going through the list's NULL terminated str array contents
char	**ft_nodbinstrarrjoin_from_back(t_dlist *list);
// Allocates and returns a string that is the concatenation of going through
// the list's str contents
char	*ft_nodbinstrjoin_from_back(t_dlist *list);

#endif /* FT_LIBFTDLIST_H */
