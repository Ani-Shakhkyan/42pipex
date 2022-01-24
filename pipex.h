/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashakhky <ashakhky@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:23:09 by ashakhky          #+#    #+#             */
/*   Updated: 2022/01/24 16:23:26 by ashakhky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

char	*ft_strjoin(char *path, char *bin);
int		ft_strncmp(char *str1, char *str2, int n);
int		ft_strchr(char *str, char c);
char	*ft_strndup(char *str, unsigned int n);
char	**ft_split(char *str, char sep);
size_t	ft_strlen(const char *str);

#endif
