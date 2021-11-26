#ifndef FT_LIBFTFILELIST_H
# define FT_LIBFTFILELIST_H

enum e_redirection_mode
{
	REDIR_VOID,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
	REDIR_NONE
};

typedef struct s_filelist
{
	char					*filename;
	enum e_redirection_mode	mode;
	struct s_filelist		*next;
}	t_filelist;

# include <stdlib.h>

// Adds the element 'new' at the end of the list.
void		ft_filelistadd_back(t_filelist **lst, t_filelist *new);
// Frees the list using the function 'del'.
// Finally, the pointer to the list is set to NULL.
void		ft_filelistclear(t_filelist **lst, void (*del)(void *));
// Frees memory associated with 'node' that is of t_filelst* type.
void		ft_filelistdel(void *node);
// Applies the function 'del' on 'lst'.
// The memory of 'next' is not freed.
void		ft_filelistdelone(t_filelist *lst, void (*del)(void *));
// Allocates and returns a new element t_filelst *result;
t_filelist	*ft_filelistnew(char *filename, enum e_redirection_mode mode);

#endif /* FT_LIBFTFILELIST_H */
