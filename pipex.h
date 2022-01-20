#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

char	*ft_strjoin (char *path, char *bin);
int		ft_strncmp (char *str1, char *str2, int n);
int		ft_strchr (char *str, char c);
char	*ft_strndup (char *str, unsigned int n);
char	**ft_split (char *str, char sep);

#endif
