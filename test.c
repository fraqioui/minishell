// #include<stdio.h>
// #include<signal.h>

#include<stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
// int main(int ac, char **av, char **env)
// {
// 	char *s = readline("minibash $> ");
// }

// int main(int ac, char **av, char **env)
// {
// 	struct sigaction	sa;
// 	while(1);
// 	sigaction(SIGINT, NULL, NULL);
// }

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>
#include<sys/wait.h>

// struct sigaction old_action;

// void sigint_handler(int sig_no)
// {
//     printf("CTRL-C pressed\n");
//     sigaction(SIGINT, &old_action, NULL);
//     kill(0, SIGINT);
// }

// int main()
// {
//     struct sigaction action;
//     memset(&action, 0, sizeof(action));
//     action.sa_handler = &sigint_handler;
//     sigaction(SIGINT, &action, &old_action);
// 	char *s;
// 	while (1)
// 	{
// 		s = readline("$> ");
// 		if (s == NULL)
// 		{
// 			printf("\n");
// 			exit(0);
// 		}
// 	}
//     return 0;
// }

// void sigint_handler(int signo) {
//     // printf("Caught SIGINT\n");
// }

// int main(int ac, char **av, char **env) {
//     // signal(SIGINT, sigint_handler);
//     struct sigaction s;
//     s.sa_handler = sigint_handler;
//     sigemptyset(&s.sa_mask);
//     s.sa_flags = SA_RESTART;
//     sigaction(SIGINT, &s, NULL);
//     pid_t   p = fork();
//     if (p == 0)
//     {
//         while (1);
//     }
//     else
//     {
//         wait(NULL);
//         char *s[3] = {av[1], av[2], NULL};
//         execve("/usr/bin/wc", s, env); 
//          printf("par\n");            /* Infinite loop */
//     }
// }
#include"headers/minishell.h"

int main(int ac, char **av)
{
    char *s = readline("");
    char **p = ft_split(s);
    for(int i = 0;p[i]; i++)
        printf("%s\n", p[i]);
}
