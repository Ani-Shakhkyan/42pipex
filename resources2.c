#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	const char	*end;

	if (!str)
		return (0);
	end = str;
	while (*end)
		end++;
	return (end - str);
}
