#ifndef FT_LIBFTSORT_H
# define FT_LIBFTSORT_H

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
void	ft_merge_sort_int(int *array, t_2_int start_end_indexes,
			int *helper_array);
// Uses merge sort algorithm to sort 'array' from 'start_index' to 'end_index'
// with the help of 'helper_array' that must be at least size of
// end_index - start_index
// Ex. usage: char *arr[10], int *helper[10]
// ft_merge_sort_str(arr, (t_2_int){0, 10}, helper);
void	ft_merge_sort_str(char **array, t_2_int start_end_indexes,
			char **helper_array);

#endif /* FT_LIBFTSORT_H */
