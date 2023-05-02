#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<limits.h>
// #include"headers/minishell.h"
// int	_cd_(char *path, char **env)
// {
// 	char	s[PATH_MAX];

// 	if (!path)
// 	{
// 		path = get_env("HOME");
// 		if (!path)
// 		{
// 			ft_putstr_fd("bash: cd: HOME not set\n", 2);
// 			return (-1);
// 		}
// 	}
// 	if (getcwd(s, PATH_MAX) < 0 && errno == ENOENT)
// 	{
// 		ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot \
// 		access parent directories: No such file or directory\n", 2);
// 		return (-1);
// 	}
// 	if (chdir(path) < 0)
// 	{
// 		ft_printf("bash: cd: %s: ", path);
// 		perror("");
// 		return (-1);
// 	}
// 	return (0);
// }

// int main(int ac, char **av, char **env)
// {
//     char s[PATH_MAX];
//     (void)ac;
//     (void)av;

//     printf(". %s\n", getcwd(s, PATH_MAX));
//     _cd_("hi", env);
//     printf(". %s\n", getcwd(s, PATH_MAX));
// }

// int main(int ac, char **av, char **env)
// {
// 	(void)ac;
// 	(void)av;

// 	char *s = get_env("");
// 	puts("bash: get_env: \n");
// 	perror("");
// 	printf("%s\n", s);
// }

// void	fc(char **s)
// {
// 	int i = 0;
// 	while (i < 5)
// 	{
// 		*(*s)++ = 'g';
// 		printf("%c\n", *((*s) - 1));
// 		i++;
// 	}
// }

// int main()
// {
// 	char *s = malloc(sizeof(char) * 6);
// 	*s++ = 'h';
// 	fc(&s);
// 	*s++ = 'h';
// 	*s = '\0';
// 	s -= 4;
// 	printf("%s\n",s);
// }

 #include <dirent.h>

int seardir(void)
{
	DIR *dp = opendir(".");
	struct dirent *entry;

	for (entry=readdir(dp);entry!=NULL;entry=readdir(dp))
		printf("%s\n", entry->d_name);
	closedir(dp);
	return (1);
}

int main()
{
	seardir();
}

/*
EACCES
The file permissions don’t allow the calling process to open the file in the
mode specified by flags. Alternatively, because of directory permissions,
the file could not be accessed, or the file did not exist and could not be
created.
EISDIR
The specified file is a directory, and the caller attempted to open it for
writing. This isn’t allowed. (On the other hand, there are occasions when it
can be useful to open a directory for reading. We consider an example in
Operating Relative to a Directory File Descriptor.)
EMFILE
The process resource limit on the number of open file descriptors has been
reached (RLIMIT_NOFILE, described in Details of Specific Resource Limits).
ENFILE
The system-wide limit on the number of open files has been reached.
ENOENT
The specified file doesn’t exist, and O_CREAT was not specified, or O_CREAT
was specified, and one of the directories in pathname doesn’t exist or is a
symbolic link pointing to a nonexistent pathname (a dangling link).
EROFS
The specified file is on a read-only file system and the caller tried to open it
for writing.
ETXTBSY
The specified file is an executable file (a program) that is currently
executing. It is not permitted to modify (i.e., open for writing) the
executable file associated with a running program. (We must first terminate
the program in order to be able to modify the executable file.)
*/