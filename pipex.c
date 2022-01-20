#include "pipex.h"

char *find_path(char *first, char **envp)
{
	int i;
	char *path;
	char *temp;
	char *command;

	i = 0;
	while(envp[i])
	{
		if(!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = envp[i] + 5;
			temp = ft_strndup(path,ft_strchr(path,':'));
			command = ft_strjoin(temp,first);
			if(!access(command,F_OK))
			{
				return command;
			}
			free(temp);
			free(command);
			path += ft_strchr(path, ':');
		}
		i++;
	}
	return first;

}

void first_path(char *cmd, char **envp)
{
	char **commands;
	char *path;

	commands = ft_split(cmd,' ');
	if(ft_strchr(commands[0],'/')>=0)
		path = commands[0];
	else
		path = find_path(commands[0],envp);
	execve(path,commands,envp);
	write(2,"Command could not be found",27);
	exit(127);
}

void first_cmd(int input_fd, char *cmd, char **envp)
{
	int pfd[2];
	pid_t pid;

	pipe(pfd);
	pid = fork();
	if(pid == 0)
	{
		close(pfd[0]);
		dup2(pfd[1],1);
		if(input_fd == 0)
			exit(1);
		else
			first_path(cmd, envp);
		
	}
	else
	{
		close(pfd[1]);
		dup2(pfd[0],0);
		waitpid(pid,NULL,0);
	}
}

int main(int argc, char **argv,char** envp){



	if(argc == 5)
	{
		int input;
		int output;

		input = open(argv[1],O_RDONLY);
		output = open(argv[4],O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
		if(input == -1 || output == -1)
			perror("There was a problem with opening the files");
		dup2(input,STDIN_FILENO);
		dup2(output,STDOUT_FILENO);
		first_cmd(input, argv[2], envp);
		first_path(argv[3],envp);
	}
	else
		write(2, "Number of arguments wasn't sufficient",37);
}
