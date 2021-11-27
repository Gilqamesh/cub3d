#ifndef FT_LIBFTSLIST_H
# define FT_LIBFTSLIST_H

# include <stdlib.h>
# include <stdbool.h>

// Singly-linked list
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Adds the element 'new' at the end of the list.
void	ft_lstadd_back(t_list **lst, t_list *new);
// Adds the element 'new' at the beginning of the list.
void	ft_lstadd_front(t_list **lst, t_list *new);
// Deletes and frees the given element and every successor of that element,
// using the function 'del' and free.
// Finally, the pointer to the list is set to NULL.
void	ft_lstclear(t_list **lst, void (*del)(void *));
// Frees node->content and node, where node is of type *t_list
void	ft_lstdel(void *node);
// Takes as a parameter an element and frees the memory of the element's
// content using the function 'del' given as a parameter and free the element.
// The memory of 'next' is not freed.
void	ft_lstdelone(t_list *lst, void (*del)(void *));
// Iterates the list 'lst' and applies the function 'f' to the content of each
// element.
void	ft_lstiter(t_list *lst, void (*f)(void *));
// Returns the last element of the list.
t_list	*ft_lstlast(t_list *lst);
// Free all addresses stored in 'lst' then clears lst and sets
// it to NULL
void	ft_lstmallocfree(t_list **lst);
// Malloc instead it also adds the address into 'lst'
// Use ft_lstmallocfree to free all the saved addresses
void	*ft_lstmallocwrapper(t_list **lst, size_t size, bool is_calloc);
// Iterates the list 'lst' and applies the function 'f' to the content of each
// element. Creates a new list resulting of the successive application of the
// function 'f'. The 'del' function is used to delete the content of an element
// if needed.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// Allocates and returns a new element. The variable 'content' is initialized
// with the value of the parameter 'content'. The variable 'next' is
// initialized to NULL.
t_list	*ft_lstnew(void *content);
// Prints out the contents of list, up to 'n' times, if 'n' is negative,
// the functions prints out the entire list.
void	ft_lstprint_int(t_list *lst, int n);
// Counts the number of elements in the list.
int		ft_lstsize(t_list *lst);
// inserts 'new' into 'lst' in a way that *(int *) 'content' is in ascending
// order
void	ft_lstsortedinsert_int(t_list **lst, t_list *new);

#endif /* FT_LIBFTSLIST_H */
