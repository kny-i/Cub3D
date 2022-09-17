#include "cub3d.h"

void	*xmalloc(size_t len)
{
	void	*ptr;

	ptr = malloc(len);
	if (ptr == NULL)
		error_message("Error\n" \
		"malloc failure!");
	return (ptr);
}

void	*xcalloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (ptr == NULL)
		error_message("Error\n" \
		"calloc failure");
	return (ptr);
}
