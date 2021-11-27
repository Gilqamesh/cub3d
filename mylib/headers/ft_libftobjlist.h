#ifndef FT_LIBFTOBJLIST_H
# define FT_LIBFTOBJLIST_H

# include <stdlib.h>

typedef struct s_obj_lst
{
	char				*key;
	char				*value;
	struct s_obj_lst	*next;
}	t_obj_lst;

// Frees the list using the function 'del' and free.
// Finally, the pointer to the list is set to NULL.
void		ft_objlst_clear(t_obj_lst **lst, void (*del)(void *));
// Frees node->content and node, where node is of type *t_obj_lst
void		ft_objlst_del(void *node);
// Applies the function 'del' on 'lst'.
// The memory of 'next' is not freed.
void		ft_objlst_delone(t_obj_lst *lst, void (*del)(void *));
// Finds the str 'key' in the list 'head' and returns the address to it.
t_obj_lst	*ft_objlst_findbykey(t_obj_lst *head, char *key);
// Creates a list using the NULL terminated 'strArr' and returns a pointer to it
// In reverse order, using ft_objlst_front.
t_obj_lst	*ft_objlst_mapFromEnv(char **strArr);
// Allocates and returns a new element t_obj_lst *result;
t_obj_lst	*ft_objlst_new(char *key, char *value);
// Find 'node' in t_obj_lst 'lst' and deletes it keeping the rest of the list
// intact.
void		ft_objlst_rem(t_obj_lst **lst, t_obj_lst *node);
// Adds the element 'new' at the beginning of the list.
void		ft_objlstadd_front(t_obj_lst **lst, t_obj_lst *new);
// Inserts the element 'new' to 'lst' by the alphabetical ordering of new->key.
void		ft_objlstinsert(t_obj_lst **lst, t_obj_lst *new);

#endif /* FT_LIBFTOBJLIST_H */
