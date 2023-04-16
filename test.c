#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<limits.h>
#include"headers/minishell.h"
int	_cd_(char *path, char **env)
{
	char	s[PATH_MAX];

	if (!path)
	{
		path = getenv("HOME");
		if (!path)
		{
			ft_putstr_fd("bash: cd: HOME not set\n", 2);
			return (-1);
		}
	}
	if (getcwd(s, PATH_MAX) < 0 && errno == ENOENT)
	{
		ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot \
		access parent directories: No such file or directory\n", 2);
		return (-1);
	}
	if (chdir(path) < 0)
	{
		ft_printf("bash: cd: %s: ", path);
		perror("");
		return (-1);
	}
	return (0);
}

int main(int ac, char **av, char **env)
{
    char s[PATH_MAX];
    (void)ac;
    (void)av;

    printf(". %s\n", getcwd(s, PATH_MAX));
    _cd_("hi", env);
    printf(". %s\n", getcwd(s, PATH_MAX));
}
