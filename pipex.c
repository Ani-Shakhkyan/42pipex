/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashakhky <ashakhky@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:01:07 by ashakhky          #+#    #+#             */
/*   Updated: 2022/01/24 16:22:26 by ashakhky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_traverse_path(char *path)
{
	char	*temp;
	char	*command;

	while (*path)
	{
		temp = ft_strndup(path, ft_strchr(path, ':') - 1);
		command = ft_strjoin(temp, first);
		if (!access(command, F_OK))
		{
			free(temp);
			return (command);
		}
		free(temp);
		free(command);
		path += ft_strchr(path, ':');
	}
	return (NULL);
}

char	*find_path(char *first, char **envp)
{
	int		i;
	char	*cmd;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			cmd = ft_traverse_path(envp[i] + 5);
			if (cmd)
				return (cmd);
		}
		i++;
	}
	return (first);
}

void	execute(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (args[0][0] == '/')
		path = args[0];
	else
		path = find_path(args[0], envp);
	execve(path, args, envp);
	write(2, "Command could not be found\n", 27);
	exit(127);
}

void	first_cmd(int input_fd, char *cmd, char **envp)
{
	int		pfd[2];
	pid_t	pid;

	pipe(pfd);
	pid = fork();
	if (pid == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		if (input_fd == 0)
			exit(1);
		else
			execute(cmd, envp);
	}
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	input;
	int	output;

	if (argc == 5)
	{
		input = open(argv[1], O_RDONLY);
		output = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
		if (input == -1 || output == -1)
		{
			perror("There was a problem with opening the files");
			return (1);
		}
		dup2(input, STDIN_FILENO);
		dup2(output, STDOUT_FILENO);
		first_cmd(input, argv[2], envp);
		execute(argv[3], envp);
	}
	else
		write(2, "Number of arguments wasn't sufficient\n", 38);
}
